![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Gabriel Carvajal (Bitácora)
* Pablo Rodríguez (Coordinador)

## Resumen 

> Con el algoritmo de reconocimiento de caras listo, nos dedicamos a hacer que el programa guarde las caras en una lista con nexo.

## 1. Introducción

Para poder trabajar con las caras detectadas por nuestro programa necesitamos guardar dichas caras en algún lado, y en este caso elegimos crear una lista con nexo que admitiera una matriz (tipo de dato con el cual trabaja OpenCV) para guardarla. Elegimos crear dichos arreglos a mano, dos exactamente, uno para los nexos y el otro para la lista con nexo.
### 1.1 Descripción del problema
Almacenar caras en una lista con nexo para poder trabajar con ellas (Comparar, eliminar, contar, etc)
### 1.2 Objetivos 

**Objetivo General**

Implementar arreglos a nuestro programa que nos ayuden a almacenar caras como nodos de una lista con nexo.

**Objetivos específicos**

1. Investigar la compatibilidad de listas con nexo con el tipo de dato "Mat".
2. Crear las clases "Nodo" y "LinkedList".
3. Implementar las clases creadas en el main.
4. Implementar el algoritmo que guarda caras en una lista con nexo.

### 1.3 Solución propuesta

Crear nuestras propias clases sin recurrir a una librería, así podemos trabajar con el tipo de dato específico que nos entrega OpenCV y guardar las caras detectadas por nuestro algoritmo en nuestra lista con nexo.

## 2. Materiales y métodos

Lenguaje de programación C++, librería OpenCV.

### 2.1 Instalación

Describir brevemente las librerías utilizadas para la instalación y programas utilizados para la ejecución del código. (Agregar una sección de anexo para describir como fueron instaladas las librerías de OpenCV y la IDE utilzada para el trabajo)

### 2.2 Diseño 


![UCN](images/DiagramaHistoria2.png)

Para darle una mejor organización al código decidimos utilizar una clase llamada MenuRial la cual sólo tiene un constructor, pero dentro del constructor hace la implementación de un menú bastante simple para poder ir navegando entre las 2 historias ahora disponibles. La navegación de las funcionalidades se realiza con el teclado donde se puede ingresar la tecla que se indique ya sea en minúscula o mayúscula para poder acceder a la historia que se desee, por otro lado se puede utilizar el 0 para darle fin al programa.

![UCN](images/MenuUsuario.png)

Luego de haber elegido una historia con uso del teclado, se llama a la clase de la historia que corresponda. Ambas clases son muy parecidas en el sentido de que se implementan en su constructor, se decidió esto ya que la implementación no es muy extensa en tema de líneas gracias a la librería. La diferencia que tienen estas clases es que como se puede ver en el diagrama la historia 2 se implementó haciendo uso de una clase llamada LinkedList que a su vez usa otra clase llamada Node, con el fin de implementar una LinkedList sin hacer uso de librerías y además solo con los métodos que realmente se utilizaron. Consideramos esto como ventaja ya que para mostrar el Top5 de rostros que aparecieron(Método que aún no está implementado en su totalidad debido a problemas con la comparación de rostros) se usó la siguiente función personalizada para mostrar las imágenes, esta función puede servir cuando se logre tener la LinkedList ordenada:

```c++
1. void LinkedList::show() {
2.    // Muestra el top 5 y luego las destruye para dar el efecto de q se cerro la historia
3.    Node* aux = first;
4.    string top = "Top ";
5.    for (int i = 1; i <= 5; i++) {
6.        top = top + to_string(i);
7.        cv::resize(aux->cara, aux->cara, cv::Size(), 4, 4);
8.        cv::imshow(top, aux->cara);
9.        aux = aux->next;
10.       top = "Top ";
11.   }
12.   cv::waitKey(0); // Para q las imagenes mostradas no desaparezcan
13.   for (int i = 1; i <= 5; i++) {
14.       top = top + to_string(i);
15.       cv::destroyWindow(top);
16.       top = "Top ";
17.   }
18.}
```

### 2.3 Implementación

Para poder lograr la implementación de la historia 2 se usó un código muy parecido al de la historia anterior la diferencia fue el tener que añadir las caras a la linkedlist, esta linkedlist almacena las caras en un tipo de dato llamado Mat que se tiene gracias a la librería, el problema es que la función que detecta las caras y las almacena en un vector almacena datos de tipo Rect. Este tipo de dato no nos sirve para trabajar ya que si deseamos mostrar fotos por pantalla o trabajar con imágenes se trabaja generalemente con datos de tipo Mat. Pero lo bueno de este tipo de dato (Rect) es que nos entrega las coordenadas de la cara en el frame, esto si resulta muy útil ya que podemos recortar la imagen del frame y así obtener el rostro como tipo Mat.

#### Almacenamiento en LinkedList

Este es el código que se utilizó para poder conseguir las caras en tipo de dato Mat y asi poder almacenarlas en la LinkedList:

```c++
1. LinkedList listacaras = LinkedList();
2.	for (Rect area : faces){
3.	 Rect roi(Point(cvRound(area.x * scale), cvRound(area.y * scale)),
4.		Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)))
5.		listacaras.add(foto_familia(roi));
6.	}
7.	listacaras.show();
```
- Primera línea: Crea la LinkedList a utilizar para almacenar las caras.
- Segunda línea: Inicializa un ciclo for que itera por un vector donde están almacenadas todas las caras como tipo de dato Rect.
- Tercera y Cuarta línea: Se le pasan las coordenadas del rostro a la función roi() para luego poder recortar la cara del frame principal.
- Quinta línea: Añade la cara a la linked list, se utiliza roi dentro de la función para mandar la cara recortada.
- Séptima línea: Utiliza el método explicado anteriormente para poder desplegar el top5 de caras.
- 
## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018
