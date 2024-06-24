# Baricentric Projection

Esto es una prueba de una nueva técnica de proyección 3D de vértices a través del baricentro de un polígono.

## Explicación de la técnica

Primero, calculamos el baricentro de todos los polígonos de un modelo 3D. Una vez calculados los baricentros, determinamos la proporción o los pesos de los vértices de un polígono en relación con el baricentro del polígono. El proceso sería el siguiente:

1. Calculamos el baricentro de un polígono de 3 vértices:

   Sea $\ v1, v2, v3 \subseteq \mathbb{R}^3$ el conjunto de vértices del polígono y \( B \) el baricentro. El cálculo del baricentro es:

   $$ B.x = \frac{v1.x + v2.x + v3.x}{3} $$
   $$ B.y = \frac{v1.y + v2.y + v3.y}{3} $$
   $$ B.z = \frac{v1.z + v2.z + v3.z}{3} $$

2. Calculamos la proporción de los vértices respecto al baricentro:

   Definimos $ {\alpha}, {\beta}, {\gamma} $ como los vectores que representan la proporción de los vértices en relación con el baricentro:

   - Proporción en $ v1 $:
     $$ {\alpha}.x = \frac{v1.x}{B.x}, \quad {\alpha}.y = \frac{v1.y}{B.y}, \quad {\alpha}.z = \frac{v1.z}{B.z} $$

   - Proporción en $ v2 $:
     $$ {\beta}.x = \frac{v2.x}{B.x}, \quad {\beta}.y = \frac{v2.y}{B.y}, \quad {\beta}.z = \frac{v2.z}{B.z} $$

   - Proporción en $ v3 $:
     $$ {\gamma}.x = \frac{v3.x}{B.x}, \quad {\gamma}.y = \frac{v3.y}{B.y}, \quad {\gamma}.z = \frac{v3.z}{B.z} $$
