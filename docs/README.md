![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Gabriel Carvajal (Bitácora)
* Pablo Rodríguez (Coordinador)

## Resumen 

> Para esta primer entrega de nuestro taller, nos enfocamos en la instalación de las herramientas necesarias para trabajar. Primero nos informamos acerca de la librería OpenCV, aprendimos que sirve para trabajar con reconocimiento de patrones en imágenes, buscamos la mejor opción de IDE para trabajar con esta librería decidiéndonos por Visual Studio Code, ya que la mayoría de documentación recomendaba usar dicha IDE. Mediante videos tutoriales, leer documentación y un poco de ingenio de nuestra parte pudimos instalar tanto la IDE como la librería OpenCV. Una vez instaladas aprendimos a reconocer una imagen para completar la primera entrega de este taller.
## 1. Introducción

Como grupo debemos construir un sistema de vigilancia para la empresa ACME, y el guardia de la empresa quiere observar todas las caras detectadas en pantallas identificadas con un cuadrado rojo, para ello como grupo decidimos usar la librería OpenCV la cual nos ayudará en este trabajo. OpenCV es una librería que nos permite reconocer rostros en imágenes estáticas o en movimiento (videos), y tiene la particularidad de ser fácil de usar y de implementar, lo que haremos en esta oportunidad será instalar una IDE y descargar e instalar la librería para su correcto manejo, nuestro programa será implementado en código C++ y guardado en github.

### 1.1 Descripción del problema
Se requiere crear un programa que al pasarle una imagen como parámetro, identifique todos los rostros humanos que encuentre y los encierre en un circulo rojo.

### 1.2 Objetivos 

**Objetivo General**

Identificar rostros en una imagen usando la librería OpenCV.

**Objetivos específicos**

1. Instalar la IDE Visual Studio Code
2. Instalar la librería OpenCV
3. Aprender funcionalidades de la librería
4. Implementar las funciones en un programa
5. Escanear rostros 

### 1.3 Solución propuesta

Esbozo de la solución propuesta, se espera que esta vaya evolucionando a medida que se avanza en el proyecto.

## 2. Materiales y métodos

Mediante tutoriales de youtube y documentación de OpenCV, instalaremos e implementaremos dicha librería para luego trabajar con ella.

### 2.1 Instalación

Primero decidimos cuál IDE usar para este proyecto y nos decidimos por Visual Studio Code ya que es la recomendada por la documentación de OpenCV, luego la instalamos desde su página web (ver Anexo B). Una vez instalada la IDE, descargamos la librería OpenCV de su página web y configuramos Visual Studio Code para poder utilizarla (ver Anexo A).

### 2.2 Implementación

Explicar brevemente algunos aspectos de implementación: Por ejemplo, detector de caras utilizado. Se pueden realizar pequeñas reseñas al código para indicar elementos importantes en el trabajo.

Por ejemplo, 

#### Detector de caras

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:

```c++
 1. faceCascadePath = "./haarcascade_frontalface_default.xml";
 2. faceCascade.load( faceCascadePath )
 3. std::vector<Rect> faces;
 4. faceCascade.detectMultiScale(frameGray, faces);

 5. for ( size_t i = 0; i < faces.size(); i++ )
 6. {
 7.  int x1 = faces[i].x;
 8.  int y1 = faces[i].y;
 9.  int x2 = faces[i].x + faces[i].width;
10.  int y2 = faces[i].y + faces[i].height;
11. }
```
La primera linea carga el archivo de entrenamiento... etc

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referencia

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018
