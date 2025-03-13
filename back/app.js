const express = require('express');
const axios = require('axios');
const app = express();
const port = 3001;

// Configuração do IP do ESP8266 - atualize com o IP do seu ESP8266
const ESP_IP = 'http://192.168.1.100'; // Substitua pelo IP do seu ESP8266

app.get('/estrategia/:status', async (req, res) => {
  try {
    const response = await axios.get(`${ESP_IP}/status`);
    res.json(response.data);
  } catch (error) {
    res.status(500).json({ error: 'Falha ao obter status' });
  }
});

app.listen(port, () => {
  console.log(`Servidor rodando em http://localhost:${port}`);
});