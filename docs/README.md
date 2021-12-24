![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Gabriel Carvajal (Bitácora)
* Pablo Rodríguez (Coordinador)

## Resumen 

> Esta entrega aborda de la historia 1 hasta la historia 6, es decir, todas las historias requeridas para el taller. En esta ocasión se pidió realizar la entrega haciendo uso de  un árbol del tipo AVL. Entonces se creó una clase capaz de adaptarse a la arquitectura propuesta, para así trabajar con sólo una clase y utilizar todas sus funciones. Todo esto haciendo uso de la librería OpenCV más lo estudiado en las clases de Estructuras de Datos.

## 1. Introducción

Lo primero que nos tuvimos que plantear fue como implementar un árbol del tipo AVL para que se adaptará a nuestras necesidades ya que este taller tiene una finalidad muy particular, por lo que necesitabamos usar un tipo de árbol con las funciones adecuadas y sólo las necesarias para poder trabajar con un código más ordenado y más personalizado. Luego de tenerlo implentado había que agregarlo a la arquitectura de tal forma que no arruinara las otras funcionalidades del programa, la forma de agregarlo no es díficil solo se instancia en la historia en que se necesita. Una vez con el árbol funcional solo quedaba encontrar el algoritmo correspondiente para cada historia, para así darles solución.

### 1.1 Descripción del problema

El problema a grandes rasgos se puede dividir en 2 partes, la parte 1 sería todo lo relacionado al AVL, sus funciones, atributos y versatilidad con respecto a lo necesitado. Por lo que para resolver de forma completa la anterior parte llamada parte 1 era necesario entender bien la parte 2. La parte 2 sería el implementar las historias 2, 3, 4 y 6. Al tener claro los requisitos de estas historias se podía implementar un AVL más completo que fuera capaz de abordar todo el problema con sus funciones.

### 1.2 Objetivos 

**Objetivo General**

Entender requisitos de las historias y encontrar algortimos óptimos para su resolución. Realizar todo el manejo de datos haciendo uso de un AVL.

**Objetivos específicos**

1. Entender los requisitos de las historias para implementar AVL.
2. Implementar AVL.
3. Implementar  Historias 2, 3, 4 y 6.
4. Que las nuevas funcionalidades no alteren en gran parte la arquitectura propuesta.

### 1.3 Solución propuesta

Crear una clase llamada AVLTree la cual utiliza otra clase para sus nodos llamada AVL, esta clase posee funciones para insertar al nodo raíz, además de poder hacer las 4 rotaciones características de un AVL con el fin de poder mantenerlo balanceado, también se tiene funciones para poder recorrerlo en preorden. Luego de tener esta clase añadirla a cada Historia (Recordar que cada historia tiene su propia clase donde se le da solución) y hacerla funcionar dentro del algoritmo que corresponda.

## 2. Materiales y métodos

Lenguaje de programación C++, librería OpenCV.

### 2.1 Diseño 

![DiagramaRelease1 0](https://user-images.githubusercontent.com/83176877/147185593-96015fcb-d046-463b-9c2e-8357d4949761.png)


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


Esta historia mantuvo la lógica de la anterior debido a que esta historia sólo pide saber cuantas personas aparecieron en el video, y como el arbol no repite personas, es decir, tiene ids únicas, solamente se necesita llevar cuenta de cuantos nodos se van creando y así se puede tener el total de personas que aparecieron. Este valor se añade cuando se hace la inserción en el árbol.

A continuación se muestra lo que ocurre dentro de la función insert del árbol AVL y la lógica a grandes rasgos de la historia 3.

Dentro del insert

```c++
1. AVL* AVLtree::insert(AVL* r, Mat im) {
2.    if (r == NULL) {
3.        r = new AVL;
4.        r->d = 1;
5.        r->im = im;
6.        r->l = NULL;
7.        r->r = NULL;
8.        cantNodos++; // Al crear un nuevo nodo se le suma a la variable que se encuentra en la clase AVLtree
9.        return r;
10.    }
11.    
12.   ... 
13. }
```

Lógica general

```c++
1.	int cont = 0; // contador para saber en que frame va la secuencia
2.	cout << muchoTexto() << endl; //Esta primera parte es para poder trabajar el video por secciones
3.	cout << "Ingrese el cuarto en el que desea trabajar:" << endl;
4.	int cuartoATrabjar;
5.	cin >> cuartoATrabjar;
6.	int frames_totales = calcularFramesTotales("Video-Practica.mp4");
7.	AVLtree avlt; //Se declara el arbol que recibirá las imagenes
8.	while (1) { 
9.		video.read(image);
10.		// esta operacion deja trabajar en el ciclo que corresponda
11.		if ((( (cuartoATrabjar - 1) * frames_totales) / 4) <= cont) {
12.        ...			
13.				avlt.insert(cf);
14.        ...}
15.      }  
16.	// Entrega el total de personas que aparecieron en la seccion del video para asi finalizar con la historia
17.	cout << "EL TOTAL DE PERSONAS IDENTIFICADAS FUE DE: " << avlt.cantNodos << endl;
18.	video.release();}
```

### Historia 4

Para realizar esta historia se utilizó el factor de que el árbol estaba ordenado por la frecuencia con que aparecía un rostro, debido a que trabajamos con un AVL en esta situación y la historia nos pide mostrar el rostro que más apareció. Utilizamos el hecho de que el rostro con mayor frecuencia debería ser el que se encontraba al final hacia la derecha. Todo esto se puede que resolver gracias a que los nodos se hicieron con atributos personalizados para responder la historia como se puede ver a continuación:

![Historia4release1 0](https://user-images.githubusercontent.com/83176877/147300381-65d37dff-d860-4c29-a1b8-dd984f5fb408.png)

Por otro lado, la función que permite obtener el rostro que más apareció haciendo uso de lo mencionado anteriormente sería la siguiente:

```c++
1.  void MostrarTop1(AVLtree avlt) {
2.    Mat Top1; // guarda imagen top 1
3.
4.    AVL* aux = avlt.root; // iterara por el árbol
5.
6.    while (1) { // Se usa para llegar hasta el nodo final
7.      if (aux->r == NULL) break;
8.      aux = aux->r;
9.    }
10.
11.   imshow(" TOP - 1 ", Top1); // despliega el rostro
12.    waitKey(0);               // hasta que se presione cualquier tecla
13.  }
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

### Historia 6

Para este problema se pedía tener un listado de las personas que aparecieron en el video junto con el tiempo en el que aparecieron. Debido a que no encontramos una buena forma de trabajar con el tiempo en OpenCV decidimos trabajar por frames. Un video tiene una cantidad finita de frames por lo tanto, una persona aparece en una cantidad finita de frames, con eso en cuenta decidimos darle un orden a los frames desde el 1 hasta el que llegara el video. Entonces a cada nodo le añadimos un vector de enteros el cual contiene el número del frame en el que apareció la persona. Entonces como se mostraba en la historia 4, cuando se hace una iteración y se le sumaba uno a la frecuencia a su vez se añade el número del frame al vector del nodo.

Aquí hubo un problema el cual era: como puede saber la función insert en que frame voy sin tener que pasarselo como atributo. Para resolver esto le añadimos un atributo al AVLtree el cual posee el frame actual a la hora de iterar el video, este atributo se va cambiando con cada iteración usando punteros para acceder a donde se encuentra alojada esa variable en la memoria. Para mejorar el entendimiento aquí se puede ver el algoritmo de como trabaja el tema del frame actual:

```c++
1.	Mat image; // imagen para trabjar
2.	AVLtree avlt; //Se declara el arbol que recibira las imagenes
3.
4.	int frame = 1;
5.
6.	int* frame_actual_avl = &avlt.frame_actual; //el puntero apunta a la direccion de la variable
7.
8.	while (1) {
9.		video.read(image);
10.     ...
11.			*frame_actual_avl = frame; //se cambia el valor de la variable antes de trabajar en el insert
12.			avlt.insert(cf); // se añade el número del frame al vector previamente nombrado
13.     ... 
14.		frame++;
15.	}
```


## 3. Resultados obtenidos

Logramos abordar el problema desde distintas estructuras de datos, en este caso que trabajamos con AVL fue muy útil para funciones como la de encontrar el top1 de persona que más apareció en el video ya que al ser un AVL y seguir cierto orden podiamos encontrar la ruta más óptima sin siquiera tener que realizar cálculos, lo cual lo vuelve increiblemente veloz. El problema que nos volvimos a encontrar a la hora de testear el codigo fue que en este taller hubo una función fundamental que fue la de la distancia euclidiana, lo malo de esta función es que consume muchos recursos y nos limitaba a la hora de trabajar con más imágenes porque nuestros computadores se ponian demasiado lentos. Esto afecta bastante ya que nos deja con la duda de como funciona el programa cuando debe manejar grandes cantidades de datos. Si bien algunas historias se trabajaron con el video, el video no superaba las 700 imágenes.



## 4. Conclusiones

Luego de haber usado distintas estructuras de datos para abordar este problema, como grupo encontramos que el trabajo con árboles conlleva grandes ventajas a la hora de búsqueda en ciertos casos. Pero el uso de árboles ya sea el ABB o el AVl encontramos que sólo vale la pena si es que se tiene un buen criterio para diferenciar los datos ya que en esto recaen funciones importantísimas como el insert, buscar, eliminar. Se requiere un buen criterio para ordenar los datos ya que si no se tiene pierde su gracia el trabajar con árboles y sale más práctico trabajar con linkedlist.

Además la diferencia entre implementar un árbol y una linked list es bastante grande, el implementar árboles en este caso fue algo muy personalizado como fue el tema de la frecuencia, el tener imágenes con los rostros, un vector con los frames, todo lo que ocurria de modo muy particular en el insert. Son cosas que quizas con una linkedlist podrían implementarse incluso con un template.

Finalmente podemos llegar a la conclusión de que si se tiene un buen criterio para ordenar el árbol los tiempos de búsqueda se reducen de una manera bastante importante que es imposible no tener en cuenta debido a la su efectividad.


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
