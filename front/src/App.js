import React, { useState } from "react";
import './App.css';
import logo from './assets/images/WolfBotz.png';
const App = () => {
  // Estado que armazena a saída de execução do código
  const [executionOutput, setExecutionOutput] = useState("");

  // Função que simula a execução do código do loop
  const executeLoopCode = (command) => {
    // Simulação de execução do comando
    if (command === "mover") {
      return "O robô está se movendo.";
    } else if (command === "parar") {
      return "O robô parou.";
    } else if (command === "girar") {
      return "O robô está girando.";
    } else if (command === "atacar") {
      return "O robô está atacando.";
    } else {
      return "Comando não reconhecido!";
    }
  };

  // Função chamada quando um botão é clicado
  const handleCommand = (command) => {
    const output = executeLoopCode(command);
    setExecutionOutput(output);
  };

  return (
    <div className="home">
      <div classNames= "header">
        <img src ={logo} className="logo"></img>
        <h1 className="Titulo">WolfBotz</h1>
      </div>


      {/* Botões de comando */}
      <div>
        <button onClick={() => handleCommand("mover")}>Mover</button>
        <button onClick={() => handleCommand("parar")}>Parar</button>
        <button onClick={() => handleCommand("girar")}>Girar</button>
        <button onClick={() => handleCommand("atacar")}>Atacar</button>
      </div>

      {/* Exibição da saída do comando */}
      <div>
        <h2>Saída do Comando:</h2>
        <p>{executionOutput}</p>
      </div>
    </div>
  );
};

export default App;
