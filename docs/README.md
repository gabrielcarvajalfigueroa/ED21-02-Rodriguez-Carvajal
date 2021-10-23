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

Explicar los componentes (módulos o clases) utilizados para resolver el problema. Indicar arquitectura propuesta, diagrama de clases u otro artefacto que estime conveniente para explicar el diseño de su implimentación.

### 2.3 Implementación

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

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018
