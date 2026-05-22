import streamlit as st
import pandas as pd
import random
import time
import plotly.express as px
import plotly.graph_objects as go
from datetime import datetime

# 1. Sayfa Konfigürasyonu
st.set_page_config(layout="wide", page_title="Hospital Pro Dashboard", page_icon="🏥")

# Modern Görünüm İçin CSS
st.markdown("""
    <style>
    .main { background-color: #0e1117; }
    div[data-testid="stMetricValue"] { font-size: 28px; color: #00d4ff; }
    div[data-testid="stMetricLabel"] { font-size: 14px; font-weight: bold; }
    .stPlotlyChart { border-radius: 10px; overflow: hidden; border: 1px solid #262730; }
    h3 { font-size: 1.1rem !important; font-weight: 600 !important; color: #ffffff; margin-bottom: 1rem !important; }
    </style>
    """, unsafe_allow_html=True)

# 2. Veri Yönetimi (Hızlandırmak için cache ve session kullanıyoruz)
if "data" not in st.session_state:
    st.session_state.data = pd.DataFrame(columns=["zaman", "klinik", "bekleme", "durum"])
    st.session_state.total = 0
    st.session_state.delay = 0

# Simülasyon: Yeni veri ekleme
zaman = datetime.now().strftime("%H:%M:%S")
klinik = random.choice(["Dahiliye", "Göz", "KBB", "Kardiyoloji", "Nöroloji"])
bekleme = random.randint(10, 95)
durum = random.choice(["Tamamlandı", "İptal", "Hata"])

new_row = pd.DataFrame([{"zaman": zaman, "klinik": klinik, "bekleme": bekleme, "durum": durum}])
st.session_state.data = pd.concat([st.session_state.data, new_row], ignore_index=True).tail(50) # Son 50 kayıt

df = st.session_state.data
total = len(df)
delayed = len(df[df["bekleme"] > 60])
avg_wait = round(df["bekleme"].mean(), 1) if not df.empty else 0

# 3. HEADER & METRİKLER
st.title("🏥 HASTANE YÖNETİM PANELİ")

# Metrikleri daha dar bir alana sıkıştıralım
m1, m2, m3, m4, m5, m6 = st.columns(6)
m1.metric("Toplam Hasta", total)
m2.metric("Geciken (60+)", delayed, delta=f"{delayed}", delta_color="inverse")
m3.metric("Ort. Bekleme", f"{avg_wait} dk")
m4.metric("Maksimum", f"{df['bekleme'].max()} dk")
m5.metric("Minimum", f"{df['bekleme'].min()} dk")
m6.metric("Hata Oranı", f"%{len(df[df['durum'] == 'Hata'])/total*100:.1f}" if total > 0 else "%0")

st.markdown("---")

# 4. GRAFİK PANELİ (Tek ekrana sığması için yükseklikleri (height) sınırladık)
row1_col1, row1_col2 = st.columns([2, 1])

with row1_col1:
    st.subheader("📈 BEKLEME SÜRESİ TAKİBİ")
    fig_line = px.line(df, x="zaman", y="bekleme", markers=True, 
                       color_discrete_sequence=['#00d4ff'])
    fig_line.update_layout(height=250, margin=dict(l=20, r=20, t=10, b=20), 
                           paper_bgcolor="rgba(0,0,0,0)", plot_bgcolor="rgba(0,0,0,0)")
    st.plotly_chart(fig_line, use_container_width=True)

with row1_col2:
    st.subheader("🏥 BÖLÜM YOĞUNLUĞU")
    fig_bar = px.bar(df["klinik"].value_counts().reset_index(), x="klinik", y="count",
                     color="count", color_continuous_scale='Blues')
    fig_bar.update_layout(height=250, margin=dict(l=20, r=20, t=10, b=20), showlegend=False, coloraxis_showscale=False)
    st.plotly_chart(fig_bar, use_container_width=True)

row2_col1, row2_col2, row2_col3 = st.columns([1, 1, 1.5])

with row2_col1:
    st.subheader("📊 DURUM DAĞILIMI")
    fig_pie = px.pie(df, names="durum", hole=0.4, 
                      color_discrete_map={'Tamamlandı':'#00cc96', 'İptal':'#ef553b', 'Hata':'#ab63fa'})
    fig_pie.update_layout(height=220, margin=dict(l=10, r=10, t=10, b=10), showlegend=False)
    st.plotly_chart(fig_pie, use_container_width=True)

with row2_col2:
    st.subheader("📉 BEKLEME ARALIĞI")
    fig_hist = px.histogram(df, x="bekleme", nbins=10, color_discrete_sequence=['#636efa'])
    fig_hist.update_layout(height=220, margin=dict(l=10, r=10, t=10, b=10))
    st.plotly_chart(fig_hist, use_container_width=True)

with row2_col3:
    st.subheader("📋 SON KAYITLAR")
    # Tabloyu da küçük tutuyoruz
    st.dataframe(df.tail(6)[::-1], use_container_width=True, height=220)

# 5. UYARI MEKANİZMASI (Sidebar veya Toast kullanarak ekranı meşgul etmesini engelliyoruz)
if bekleme > 80:
    st.toast(f"🚨 KRİTİK: {klinik} bölümünde yoğunluk! ({bekleme} dk)", icon="⚠️")

# 6. DİNAMİK YENİLEME
time.sleep(2) # CPU yormamak için 2 saniyeye çıkardım
st.rerun()




