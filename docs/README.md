![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Gabriel Carvajal (Bitácora)
* Pablo Rodríguez (Coordinador)

## Resumen 

> La finalidad de esta entrega es poder resolver el problema presentado haciendo uso de otras estructuras de datos.
> En este caso se utilizaron arboles, se usaron distintos arboles para resolver de mejor manera lo que requeria cada historia.
> Se agregaron 2 historias más al programa ademas de que se le hicieron a arreglos a las historias anteriores

## 1. Introducción

Para esta entrega se pedían las historias 1, 2, 3 y 5. Ademas de usar como estructura de datos los arboles, los arboles que se utilizaron quedaron a criterio nuestro y utilizamos los que mejor se adecuaban a cada historia. En lo que respecta a las historias 1 y 2, estas ya se encontraban implementadas pero se les hicieron distintas mejoras y se adaptaron a lo que pedía esta entrega, por ejemplo, ahora la historia 1 funciona con un video en vez de una imagen y la historia 2 se implementó haciendo uso de un heaptree. Para la historia 3 se utilizó un arbol binario simple y la historia 5 no requeria uso de arboles pero si de la librería OpenCV.

### 1.1 Descripción del problema
El problema esta vez era poder encontrar una forma de diferenciar los rostros para así poder agregarlos a un arbol binario. Esto se logro gracias a la libreria OpenCV que cuenta con una funcion que calcula la diferencia euclidiana entre 2 imagenes, usando dos valores de referencia nuestro programa puede concluir si dos imagenes son similares o diferentes. Nos encontramos con algunos problemas como que cuando una persona se reia demasiado o cambiaba mucho su rostro el programa no lo reconocia como la misma persona, pero no se profundizo en la solucion de ese problema ya que nos enfocamos en el uso de arboles como estructura de datos para poder almacenar los rostros juntos a un ID.
### 1.2 Objetivos 

**Objetivo General**

Utilizar el arbol que correspondiera para poder almacenar las imagenes y responder las historias correspondientes. Ademas de encontrar un manera de guardar el video como una copia de seguridad.

**Objetivos específicos**

1. Hacer que la historia 1 funcionara con un video, en este caso uno entregado por el profesor.
2. Implementar la historia 2 haciendo uso de un heaptree ya que facilita el poder encontrar el top 5 de rostros que mas aparecieron.
3. Encontrar una forma de dividir el video en secciones para asi poder contar cuantas personas aparecieron por seccion con el fin de llevar un conteo.
4. Investigar y luego implementar una forma para poder almacenar una copia de seguridad del video en la carpeta del proyecto, para la historia 5.

### 1.3 Solución propuesta

Usar una arquitectura donde se pudiera trabajar cada historia por separado con el fin de poder repartirnos el trabajo y de que ademas las distintas historias no se afectaran entre ellas ya que seria un problema que dependieran una de la otra por que se perderia libertad a la hora de realizar la implementacion. Y también usar un arbol creado por nuestra parte y otro arbol implementado por el profesor que dicta la asignatura Juan Bekios.

## 2. Materiales y métodos

Lenguaje de programación C++, librería OpenCV.

### 2.1 Diseño 


![DiagramaClasesRealease0 3](https://user-images.githubusercontent.com/83176877/144719851-fe7e5bc6-9ee1-438b-8861-f10c8627575b.png)

La arquitectura que se utilizo para la entrega anterior se mantuvo ya que la arquitectura fue pensada para que se pudieran seguir añadiendo historias independientemente sin tener que afectar la funcionalidad del programa. Esto es muy util ya que en la clase MenuRial se levanta una interfaz grafica que puede recibir input por teclado usando la funcion de OpenCv waitKey(0); y con el parametro 0 ya que debe quedar esperando el input por un tiempo indefinido. Luego recibe un input de int que se almacena en una variable que se compara en un if anidado con otros enteros que son las representaciones de las letras (que aparecen la imagen de abajo) pero en codigo ASCII, por eso se trabaja con un entero. Luego cuando entra en el if que corresponde activa la historia que corresponde. Y finalmente toda esta logica ocurre dentro de un do-while que se cierra cuando el usuario presiona 0. Es importante que se use el do-while porque la interfaz debe desplegarse al menos una vez.

![MenuUsuarioRelease0 3](https://user-images.githubusercontent.com/83176877/144721142-c7fb52b7-712c-458a-88ce-fab9e0c805de.png)

En esta imagen se puede observar la GUI que se utilizó para esta entrega, donde se añadieron las historias 3 y 5. Esta GUI como se hablaba arriba funciona con input por teclado solo con el fin de hacer mas facil el acceso a las historias a la hora del testeo y tambien porque es mejor que hacerlo por consola. Al presionar la tecla de la historia el programa recibe el valor por teclado en codigo ASCII y lo compara en un if, todo este codigo puede encontrarse en el archivo MenuRial.cpp.

### 2.2 Implementación

### Historia 1
![608c93566e15ef0dd332238ebe374632](https://user-images.githubusercontent.com/83176877/144720921-8cfdfc8d-24bd-43f7-9154-67385bf3cd33.gif)

Como se observa en el gif ahora la historia funciona con un video, en este caso un video entregado por el profesor y que está en formato mp4. La logica de identificar las caras y encerrarlas en un cuadrado se mantiene lo unico que cambió fue que se necesito una forma de poder conseguir los frames del video para asi poder ir pasando frame por frame a un código que identificara los rostros. El poder iterar frame por frame se logró con una clase de OpenCV llamada VideoCapture y la lógica detrás de la historia sería la siguiente:

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

No se pudo realizar completamente por problemas con el heap tree.

### Historia 3
![Historia3Intro](https://user-images.githubusercontent.com/83176877/144721365-8f2862fb-0d34-4124-b9b1-c9e345a66840.png)

En este caso se varió un poco y se presento la historia en la consola en lugar de hacerlo con una GUI. Esta historia puntualmente pide que se pueda elegir una hora de inicio y fin para cortar el video. Pero como el video que utilizamos duraba apenas 1 minuto con 16 segundos. se decidió dar la opción de dividir el video en cuatro partes y que el usuario pueda elegir con cuál trabajar ingresando un número del 1 al 4 por teclado. Como resultado el video se analiza y finalmente entrega la cantidad de personas que aparecieron en la sección del video. Cada persona que va identificando se añade a un árbol binario dentro de un nodo junto con su respectivo ID.

![ce440c09fd5b08081cbe87a8675c5f0f](https://user-images.githubusercontent.com/83176877/144721969-0ef504c6-a99e-4cf5-8228-4a3fc7031752.gif)

En el gif se puede ver cómo analiza frame a frame los rostros que recibe de la sección del video, donde calcula la distancia euclidiana entre frames para decidir si es el mismo rostro o si debe añadirlo al árbol binario.

La clase del árbol binario tiene un atributo int llamado counter que lleva cuenta de cuantos id hay en el árbol, entonces para facilitar el tema de saber cuantas personas aparecieron se añadió una función get a la clase del árbol para así poder obtener la variable counter, esto debido a que es una variable privada. Es importante tener en cuenta a la hora de probar el programa que en caso de ser un video muy largo se requiere un pc con buenos componentes ya que en este caso en particular el video de 1 minuto con 16 segundos tiene 2425 frames, y como se divide en 4 partes se trabaja con mínimo 600 frames.

La lógica para poder trabajar con el video en cuatro partes no es muy difícil solo hay que usar el concepto de que se pueden leer frames y no usarlos, así hasta llegar al frame deseado. Por lo que se usa un contador para saber en qué frame va la iteración y con un par de if para saber cuándo empezar a analizar las imágenes y otro para saber cuándo terminar de analizar. Con eso en mente la lógica sería la siguiente.

```c++
1.      int cuartoATrabjar;
2.	cin >> cuartoATrabjar;
3.	int frames_totales = calcularFramesTotales("Video-Practica.mp4"); // la funcion retorna el total de frames -- implementada por nosotros
4.
5.	cout << "El cuarto elegido fue: " << cuartoATrabjar << endl;
6.	cout << "El total de frames: " << frames_totales << endl;
7.	
8.	Mat image; // imagen para trabjar
9.	while (1) { 
10.		video.read(image);
11.		
12.		// esta operacion deja trabajar en el ciclo que corresponda
13.		if ((( (cuartoATrabjar - 1) * frames_totales) / 4) <= cont) {
14.			//La magia
15.			// se cuenta la cantidad de personas que aparecieron en esa parte del video
16.			// Leemos todas las caras de los archivos de imágenes y las insertamos en el árbol
17.		}
18.		if (cont == ((cuartoATrabjar * frames_totales) / 4)) {
19.			cout << "salio del ciclo" << endl;
20.			break;
21.		} 
22.		cont++;
23.	}
24.  // Entrega el total de personas que aparecieron en la seccion del video para asi finalizar con la historia
25.	cout << "EL TOTAL DE PERSONAS IDENTIFICADAS FUE DE: " << abb.getCounter() << endl;
```


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


## 3. Resultados obtenidos
En lo que respecta a las historias 1, 2 y 3, se puede establecer una comparación ya que todas trabajan con el procesamiento de imágenes. Se pudo observar lo mucho que cambia la velocidad del procesamiento de datos en las distintas historias. La historia 1 es capaz de desplegar el video a velocidad normal a pesar de tener que procesar los datos para agregarles los cuadrados a las caras. En cambio la historia 3 baja mucho su velocidad al momento de procesar imágenes debido al uso del árbol además de las comparaciones que debe hacer con el uso de la distancia euclidiana, claramente el pc y la cantidad de datos procesados también son un factor al momento de ver la velocidad. Pero aún así resulta efectivo trabajar con arboles aunque sean simples como el binario ya que ayuda con la búsqueda y con la inserción, todo esto si es que se tiene un buen criterio para diferenciar los nodos del árbol.

Por otro lado, la historia 5 logra procesar todas las imágenes del video en este caso 2425 como ya se mencionó anteriormente. Un defecto que tiene esta historia, dependiendo de para que se le quiera es que guarda el video sin audio, debido a que sólo trabaja con los frames entonces el audio se pierde. Pero tomando en cuenta que la intención del taller era solo poder ver personas y nada relacionado con el audio, no debería ser un problema del que preocuparse.

## 4. Conclusiones
La implementación de árboles en nuestro programa nos permitió aumentar las funcionalidades de nuestro programa, pudiendo trabajar con una gran cantidad de datos de una mejor manera; sin embargo, su implementación también supuso un desafío al momento de decidir qué tipo de árbol convenía en cada historia, de todos modos pudimos comprobar que los árboles mejoran la capacidad de búsqueda y orden de las listas enlazadas, adecuándose mejor a nuestro programa.
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
