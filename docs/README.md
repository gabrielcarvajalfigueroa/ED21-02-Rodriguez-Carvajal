![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Gabriel Carvajal (Bitácora)
* Pablo Rodríguez (Coordinador)

## Resumen 

> [INSERTE RESUMEN]

## 1. Introducción

[INSERTE INTRO]

### 1.1 Descripción del problema
[INSERTE DESCRIPCION]
### 1.2 Objetivos 

**Objetivo General**

[OBJ]

**Objetivos específicos**

1.[OBJS]

### 1.3 Solución propuesta

[SOL]

## 2. Materiales y métodos

Lenguaje de programación C++, librería OpenCV.

### 2.1 Diseño 


![DiagramaClasesRealease0 3](https://user-images.githubusercontent.com/83176877/144719851-fe7e5bc6-9ee1-438b-8861-f10c8627575b.png)

La arquitectura que se utilizó para la entrega anterior se mantuvo ya que la arquitectura fue pensada para que se pudieran seguir añadiendo historias independientemente sin tener que afectar la funcionalidad del programa. Esto es muy útil ya que en la clase MenuRial se levanta una interfaz gráfica que puede recibir input por teclado usando la funcion de OpenCV waitKey(0), con el parámetro en 0 ya que debe quedar esperando el input por un tiempo indefinido. Luego recibe un input de int que se almacena en una variable que se compara en un if anidado con otros enteros que son las representaciones de las letras (que aparecen la imagen de abajo) pero en código ASCII, por eso se trabaja con un entero. Luego cuando entra en el if que corresponde activa la historia que corresponde. Y finalmente toda esta lógica ocurre dentro de un do-while que se cierra cuando el usuario presiona 0. Es importante que se use el do-while porque la interfaz debe desplegarse al menos una vez.

![MenuRelease1 0](https://user-images.githubusercontent.com/83176877/146603864-012f39a9-7b70-4b5e-93d2-95462d7be940.png)


En esta imagen se puede observar la GUI que se utilizó para esta entrega, donde se añadieron las historias 4 y 6. Esta GUI como se hablaba arriba funciona con input por teclado solo con el fin de hacer mas fácil el acceso a las historias a la hora del testeo y también porque es mejor que hacerlo por consola. Al presionar la tecla de la historia el programa recibe el valor por teclado en codigo ASCII y lo compara en un if, todo este código puede encontrarse en el archivo MenuRial.cpp.

### 2.2 Implementación

### Historia 1
![608c93566e15ef0dd332238ebe374632](https://user-images.githubusercontent.com/83176877/144720921-8cfdfc8d-24bd-43f7-9154-67385bf3cd33.gif)

Como se observa en el gif ahora la historia funciona con un video, en este caso un video entregado por el profesor y que está en formato mp4. La lógica de identificar las caras y encerrarlas en un cuadrado se mantiene lo único que cambió fue que se necesito una forma de poder conseguir los frames del video para asi poder ir pasando frame por frame a un código que identificara los rostros. El poder iterar frame por frame se logró con una clase de OpenCV llamada VideoCapture y la lógica detrás de la historia sería la siguiente:

```c++
1.  // Se crea un objeo de la clase VideoCapture que recibe el video en formato mp4
2.  VideoCapture cap("Video-Practica.mp4");
3. // En esta variable se almacenara el frame en el que vaya la iteracion para luego analizarlo
4. Mat frame_del_video;
5. while(1){
6.    cap.read(frame_del_video);
7.    // logica que encierra y identifica los rostros
8.    // trabaja con la variable frame_del_video que se va actualizando por cada iteracion
9. }
```

### Historia 2



### Historia 3


### Historia 4


### Historia 5
![Historia5](https://user-images.githubusercontent.com/83176877/144721059-09aee193-34b3-417f-a2a4-2068019cfae3.png)

Esta historia es más simple en comparación a las demás, cuando se activa guarda el video que se estaba usando para las distintas historias. Lo guarda en formato .avi también usando las facilidades que entrega la librería OpenCV. Queda almacenado con el nombre "CopiaDeSeguridad" en la misma carpeta en la que está el proyecto. De hecho el código de abajo es todo el código que se utiliza, que queda bastante claro al estar completamente documentado.

```c++
1.  // Crea el objeto para capturar video se le entrega el video utilizado
2.  cv::VideoCapture video("Video-Practica.mp4");
3.  // Esta variable guardara los distintos frames del Video-Practica.mp4 para copiarlos
4.  cv::Mat frame;
5.  // Se consigue la resolucion del frame para una funcion a utilizar posteriormente
6.  int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
7.  int frameHeigth = video.get(cv::CAP_PROP_FRAME_HEIGHT);
8.  // Objeto para escribir el nuevo video --  video tendra el nombre copiadeseguridad debido a la historia pedida
9.  cv::VideoWriter output("CopiaDeSeguridad.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeigth));
10. // Se itera por todos los frames que entrega el video practica
11. while (video.read(frame)){
12.   // Escribe el frame en la copia del video
13.   output.write(frame);
14. }
15. // se cierran ambos videos, actua como destructor para desocupar memoria
16. output.release();
17. video.release();
18. }
```

### Historia 6


## 3. Resultados obtenidos
[Resultados]

## 4. Conclusiones
[concl]

# Anexos

## Anexo A: Instalación librerías OpenCV
Descargamos de la página oficial, https://opencv.org/releases/, la última versión (4.5.3) y descomprimimos el archivo ZIP en donde nos acomode más. Ahora debemos editar las variables de entorno de nuestro sistema, "Propiedades del sistema"->"Opciones avanzadas"->"Variables de entorno"->"PATH"->"Editar"->"Nuevo" y ponemos la dirección donde tengamos nuestra carpeta de OpenCV seguido de "\build\x64\vc15\bin", apretamos "Aceptar" y listo.
## Anexo B: Instalación de IDE y configuración librerías OpenCV
Descargamos de la página oficial el instalador de Visual Studio 2019 (no confundir con Visual Studio Code), https://visualstudio.microsoft.com/es/downloads/, y lo ejecutamos, seguir la instalación normal de cualquier programa, al iniciarlo por primera vez nos preguntará para qué tipo de trabajo lo usaremos, escogemos "Desarrollo para el escritorio en C++".
Una vez instalado crearemos un nuevo proyecto e iremos a la barra de herramientas en la parte superior de la pantalla, ahí daremos click a "Project"->"Proyecto Properties" y nos abrirá una ventana, ahí haremos lo siguiente: en "VC++ Directories"->"Include directories"->"Edit"->"New Line" e indicamos el directorio de nuestro OpenCV seguido de "\build\include" y apretamos OK; ahora en "Library directories" hacemos lo mismo pero al indicar el directorio, agregamos lo siguiente "\build\x64\vc15" y apretamos OK; ahora vamos a "Linker" y editamos "Additional dependencies" y escribimos lo siguiente: opencv_world453d.lib, el numero después de "world" variará según la versión instalada.

# Referencia

1.  GeeksforGeeks. Recuperado de: https://www.geeksforgeeks.org/c-plus-plus/
2.  OpenCv. Recuperado de: https://opencv.org/
3.  Murtaza's Workshop. (13 de diciembre 2020). LEARN OPENCV C++ in 4 HOURS | Including 3x Projects | Computer Vision [Video]. YouTube. Obtenido de https://www.youtube.com/watch?v=2FYm3GOonhk&t=2008s
