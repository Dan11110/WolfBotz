import React from "react";
import { BrowserRouter as Router, Routes, Route, useNavigate } from "react-router-dom";
import './App.css';
import logo from './assets/images/WolfBotz.png';
import Seguidor from './seguidor'; 

const Home = () => {
  const navigate = useNavigate();


  const handleCommand = (command) => {
    fetch(`http://localhost:3001/estrategia/${command}`, {
      method: "GET",
      headers: { "Content-Type": "application/json" },
      mode: "no-cors"
    });
  };

  return (
    <div className="home">
      <div className="header">
        <img src={logo} className="logo" alt="Logo" />
        <h1 className="Titulo">WolfBotz</h1>
      </div>

      <div className="comandos">
        <button onClick={() => handleCommand("Frente")}>Frente</button>
        <button onClick={() => handleCommand("Trás")}>Trás</button>
        <button onClick={() => handleCommand("Esquerda")}>Esquerda</button>
        <button onClick={() => handleCommand("Direita")}>Direita</button>
      </div>

      <div style={{ marginTop: '20px' }}>
        <button onClick={() => navigate('/Seguidor')}>Seguidor</button>
      </div>
    </div>
  );
};

// Componente principal com rotas
const App = () => {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/Seguidor" element={<Seguidor />} />
      </Routes>
    </Router>
  );
};

export default App;
