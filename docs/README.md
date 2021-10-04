![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Gabriel Carvajal (Bitácora)
* Pablo Rodríguez (Coordinador)

## Resumen 

> Para esta primer entrega de nuestro taller, nos enfocamos en la instalación de las herramientas necesarias para trabajar. Primero nos informamos acerca de la librería OpenCV, aprendimos que sirve para trabajar con reconocimiento de patrones en imágenes, buscamos la mejor opción de IDE para trabajar con esta librería decidiéndonos por Visual Studio 2019, ya que la mayoría de documentación recomendaba usar dicha IDE. Mediante videos tutoriales, leer documentación y un poco de ingenio de nuestra parte pudimos instalar tanto la IDE como la librería OpenCV. Una vez instaladas aprendimos a reconocer una imagen para completar la primera entrega de este taller.
## 1. Introducción

Como grupo debemos construir un sistema de vigilancia para la empresa ACME, y el guardia de la empresa quiere observar todas las caras detectadas en pantallas identificadas con un cuadrado rojo, para ello como grupo decidimos usar la librería OpenCV la cual nos ayudará en este trabajo. OpenCV es una librería que nos permite reconocer rostros en imágenes estáticas o en movimiento (videos), y tiene la particularidad de ser fácil de usar y de implementar, lo que haremos en esta oportunidad será instalar una IDE y descargar e instalar la librería para su correcto manejo, nuestro programa será implementado en código C++ y guardado en github.

### 1.1 Descripción del problema
Se requiere crear un programa que al pasarle una imagen como parámetro, identifique todos los rostros humanos que encuentre y los encierre en un circulo rojo.

### 1.2 Objetivos 

**Objetivo General**

Identificar rostros en una imagen usando la librería OpenCV.

**Objetivos específicos**

1. Instalar la IDE Visual Studio 2019
2. Instalar la librería OpenCV
3. Aprender funcionalidades de la librería
4. Implementar las funciones en un programa
5. Escanear rostros 

### 1.3 Solución propuesta

Esbozo de la solución propuesta, se espera que esta vaya evolucionando a medida que se avanza en el proyecto.

## 2. Materiales y métodos

Mediante tutoriales de youtube y documentación de OpenCV, instalaremos e implementaremos dicha librería para luego trabajar con ella.

### 2.1 Instalación

Primero decidimos cuál IDE usar para este proyecto y nos decidimos por Visual Studio 2019 ya que es la recomendada por la documentación de OpenCV, luego la instalamos desde su página web (ver Anexo B). Una vez instalada la IDE, descargamos la librería OpenCV de su página web y configuramos Visual Studio 2019 para poder utilizarla (ver Anexo A).

### 2.2 Implementación

Para realizar la implementación utilizamos dos clases, Historia1 y MenuRial. MenuRial se encarga de desplegar una sencilla interfaz de usuario guiada (GUI) mostrando las opciones de historia y recibiendo input del usuario sólo por teclado. Al llamar la historia en el menú, se invoca a la clase Historia1 que se encarga de analizar la imagen y desplegarla en la pantalla con los rostros identificados. Todo esto sin hacer uso de herencia. El menu se inicia en el main.

El código que se utilizo para realizar la identificación y posterior encierro en un rectángulo rojo fue el siguiente:

#### Identificador de rostros

Se utilizó un CascadeClassifier que es un modelo preentrenado que provee OpenCV para la identificación de rostros, pero hay que tener en cuenta que solo está entrenado para identificar rostros de frente.

```c++
        1. vector<Rect> faces;
	2. faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));
        3. 
	4. for (Rect area : faces)
	5. {
	6. Scalar drawcolor = Scalar(0, 0, 255);
	7.	rectangle(foto_familia, Point(cvRound(area.x * scale), cvRound(area.y * scale)),
	8.	Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawcolor);
	9. }
```
Primera línea: Declara un vector para almacenar los rostros.(Muy útil ya que un vector es un arreglo de tipo dinámico y no se sabe cuantos rostros se analizarán).
Segunda línea: Detecta los rostros en una imagen luego de que esta ha sido pasada a la escala de grises y los almacena en en el vector faces.
Cuarta línea: Empieza un ciclo for que iterara por todos los rostros que se hayan logrado identificar. Rostros que quedaron almacenados como datos de tipo Rect.
Sexta línea: Declara el color que se utilizará para los cuadrados que encierran los rostros, es en BGR (Blue-Green-Red) 8-bits.
Séptima y octava línea: Dibuja los rectangulos con la función rectangle(). Y usa como parámetros: la foto procesada, las coordenadas x e y del rostro gracias a que está almacenado como dato de tipo Rect, el color que se indica en este caso rojo y finalmente una variable llamada scale declarada anteriormente que se usa para cambiar la eficacia con que se detectan rostros. 

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referencia

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018
