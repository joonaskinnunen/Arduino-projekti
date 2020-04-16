# Hydromat Dripper

#### OAMK

_Joonas Kinnunen, Esa Tervonen, Tomi Uosukainen TVT20KMO_

_Tieto- ja viestintätekniikka, Ohjelmistokehityksen koulutusohjelma_

### Ohjelmoinnin sovellusprojekti

**Esittely:**
Projektin tavoitteena oli rakentaa automaattinen kastelujärjestelmä esim. pienelle huonekasville.

**Tavoite:**
Tavoitteena projektissa oli rakentaa järjestelmä, joka tarkkailee mullan/maaperän kosteutta.
Mullassa on anturi joka tarpeeksi matalan raja-arvon saatuaan antaa vesipumpulle käskyn käynnistyä ja pumpata 
vettä kasville. Ryhmän tavoitteena oli myös lisätä laitteeseen toiminto, joka tarkkailee vesisäiliön vedenmäärää 
ja veden pinnan laskeuduttua tarpeeksi, kuuluu merkkiääni säiliön täyttämiseksi.

**Lisätavoite:**
Suunnittelimme, että mikäli aika riittää lisäämme LCD-näytön joka näyttää veden määrän säiliössä raja-arvoina sekä kosteusarvon
mullassa/maaperässä.

**Ohjaus:**
 - Anturit ovat kytkettynä Arduino mikrokontrolleriin.
 - Mikrokontrolleria ohjataan ohjelmalla, joka on toteutettu C-ohjelmointikielellä. 
 - Päälle kytkettynä laite toimii täysin automaattisesti, pois lukien vesisäiliön täyttö.
