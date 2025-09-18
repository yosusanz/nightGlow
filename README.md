<h1>NightGlow</h1>

<p>
  <img src="https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white" alt="Arduino" />
  <img src="https://img.shields.io/badge/ESP32-003B57?style=flat&logo=espressif&logoColor=white" alt="ESP32" />
  <img src="https://img.shields.io/badge/licencia-Apache%202.0-green?style=flat-square" alt="Licencia: Apache 2.0">
</p> 

<section>
  <p align="center">
    <img src="https://github.com/yosusanz/yosusanz/blob/main/images/nightGlow/bannerNightGlow.png?raw=true" alt="NightGlow Intro" width="846"/>
  </p>
  
  <p align="center">ESP32 | Arduino | NeoPixel | Ultrasonidos</p>
  <br>
  <p><strong>NightGlow</strong> es un sistema de <strong>iluminación automática para la cama</strong> que utiliza sensores ultrasónicos y de luz para detectar movimiento en la oscuridad y activar una tira LED con <strong>efecto fade-in/fade-out</strong>. Su objetivo es proporcionar <strong>iluminación cómoda, eficiente y no intrusiva</strong> durante la noche.</p>
  <img src="https://github.com/yosusanz/yosusanz/blob/main/images/nightGlow/esquema.png?raw=true" alt="NightGlow - esquema de conexiones" width="846"/>
  <p>El proyecto combina la potencia de un <strong>ESP32</strong> con sensores <strong>HC-SR04</strong> y tiras LED <strong>NeoPixel</strong>, priorizando el ahorro energético y la facilidad de integración.</p>
  <img src="https://github.com/yosusanz/yosusanz/blob/main/images/nightGlow/demo-pics.png?raw=true" alt="NightGlow en funcionamiento" width="846"/>
  <br>
  
  <br>
  <h2>🛠️ Casos de uso</h2>
  <ul>
    <li><strong>Iluminación nocturna de cama</strong>: encendido automático al levantarse para evitar golpes y caídas.</li>
    <li><strong>Habitaciones infantiles</strong>: luz suave que acompaña a los niños durante la noche sin despertarles.</li>
    <li><strong>Personas mayores</strong>: mayor seguridad al desplazarse en ambientes oscuros.</li>
    <li><strong>Decoración inteligente</strong>: iluminación ambiental activada por presencia.</li>
  </ul>
  
  <br>
  <h2>🧠 Funcionalidad</h2>
  <ul>
    <li>Sensor de luz integrado: solo funciona en oscuridad.</li>
    <li>Detección de movimiento con dos sensores ultrasónicos.</li>
    <li>Filtro anti-falsos positivos: requiere 5 detecciones consecutivas antes de encender.</li>
    <li>Efectos de <strong>fade-in</strong> y <strong>fade-out</strong> al encender/apagar las tiras LED.</li>
    <li>Tiempo de encendido configurable (ejemplo: 120 segundos).</li>
    <li>Uso de tiras LED <strong>NeoPixel</strong> (WS2812) con control preciso de color y brillo.</li>
  </ul>
  
  <br> 
  <h2>⚙️ Arquitectura</h2>
  <ul>
    <li><strong>ESP32</strong> como microcontrolador principal.</li>
    <li><strong>Adafruit NeoPixel</strong> para el control de LEDs RGB direccionables.</li>
    <li><strong>NewPing</strong> para gestión eficiente de sensores ultrasónicos.</li>
    <li><strong>Programación en Arduino C++</strong> con código modular y configurable.</li>
  </ul>

  <br>
  <h2>Estructura de carpetas</h2>
  <pre><code>
    📁 src/                  # Código fuente principal
      📄 main.cpp            # Lógica principal del proyecto
    📁 include/              # Archivos de cabecera
    📁 lib/                  # Librerías adicionales
    📁 test/                 # Tests de firmware
    📄 platformio.ini        # Configuración del proyecto (PlatformIO)
  </code></pre>
  
  <br>
  <h2>🚀 Instalación y uso</h2>
  <p>Clona el repositorio y compila desde PlatformIO (VS Code recomendado):</p>
  <ol>
    <li>Conecta el ESP32 al ordenador.</li>
    <li>Abre el proyecto en PlatformIO.</li>
    <li>Compila y sube el firmware al ESP32.</li>
    <li>Conecta los sensores ultrasónicos y la tira LED según el esquema.</li>
    <li>Ajusta la sensibilidad del sensor de luz (LM393) con el potenciómetro.</li>
    <li>Al detectar movimiento en oscuridad, la tira LED se encenderá suavemente y se apagará tras el tiempo configurado.</li>
  </ol>

  <br>
  <h2>📄 Licencia</h2>
  <p>
    <strong>Apache License 2.0</strong> – puedes usar esta plantilla libremente en proyectos personales o comerciales.<br>
    Es <strong>obligatorio</strong> mantener el aviso de copyright, la licencia y cualquier nota de atribución.<br>
    Las modificaciones también deben incluir una <strong>nota explicando los cambios</strong> realizados.
  </p>

  <br>
  <p align="center"><i>Desarrollado por <a href="https://www.linkedin.com/in/yosusanz" target="_blank">@yosusanz</a> – más proyectos en mi perfil de <a href="https://github.com/yosusanz" target="_blank">GitHub</a></i></p>
</section>
