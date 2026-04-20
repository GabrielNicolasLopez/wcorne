<p align="center">
  <img width="900" alt="Wireless Corne" src="https://github.com/user-attachments/assets/0e4540cb-65be-4db0-9063-eaaef82d1726" />
</p>

<h1 align="center">Wireless HotSwap MX Ergo Split Corne Keyboard</h1>
<p align="center">Compacto, inalámbrico y pensado para aprovechar al máximo cada tecla</p>

### Layer previews

#### Base
<img width="1333" height="435" alt="image" src="https://github.com/user-attachments/assets/37bead11-6a41-495a-8050-b5f490de531b" />

#### Lower
<img width="1323" height="439" alt="image" src="https://github.com/user-attachments/assets/9eb23cf9-94f8-4bd1-9b5f-3b1fc6ae5e78" />

#### Raise
<img width="1323" height="433" alt="image" src="https://github.com/user-attachments/assets/bfa2a616-b5c0-42fd-81db-6ebc022ea842" />

#### Adjust
<img width="1323" height="433" alt="image" src="https://github.com/user-attachments/assets/99f0bac7-8d1f-44e1-ba15-74e243d0b068" />

## Imagen en display derecho (nice!view)

Este repo compila una pantalla custom solo para `corne_right` (la izquierda queda con status screen built-in).

### Cambiar la imagen

1. Convertí tu PNG a imagen de LVGL usando el converter: https://lvgl.io/tools/imageconverter
2. Elegí:
   - **Output**: `C array` (variable)
   - **Color format**: `Alpha 1-bit` (`LV_IMG_CF_ALPHA_1BIT`) recomendado para pantallas monocromo
   - **Name**: `corne_right_logo` (así no tenés que tocar el código)
3. Reemplazá el contenido de `src/corne_right_logo.c` por el archivo generado.
4. Commit + push para que GitHub Actions te genere el nuevo `.uf2`, y flashealo en la mitad derecha.

Nota: no reemplazamos el status screen de `nice_view` (eso rompe por doble definiciÃ³n). En vez de eso, `src/right_display_logo_overlay.c` agrega la imagen arriba del UI solo cuando el firmware es **peripheral** (mitad derecha).

Config recomendada:
- `corne_left.conf`: `CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM=y` (para mantener el layout de nice!view).
- `corne_right.conf`: `CONFIG_ZMK_DISPLAY_STATUS_SCREEN_BUILT_IN=y` (la imagen tapa todo si usÃ¡s 160x68).
