# Hydromat Dripper

#### OAMK

Joonas Kinnunen, Esa Tervonen, Tomi Uosukainen TVT20KMO

Tieto- ja viestintätekniikka, Ohjelmistokehityksen koulutusohjelma

Ohjelmoinnin sovellusprojekti

Esittely:
Projektin tavoitteena oli rakentaa automaattinen kastelujärjestelmä esim. pienelle huonekasville.

Tavoite:
Tavoitteena projektissa oli rakentaa järjestelmä, joka tarkkailee mullan/maaperän kosteutta.
Mullassa on anturi joka tarpeeksi matalan raja-arvon saatuaan antaa vesipumpulle käskyn käynnistyä ja pumpata 
vettä kasville. Ryhmän tavoitteena oli myös lisätä laitteeseen toiminto, joka tarkkailee vesisäiliön vedenmäärää 
ja veden pinnan laskeuduttua tarpeeksi, kuuluu merkkiääni säiliön täyttämiseksi.

Lisätavoitteena projektiin oli lisätä LCD-näyttö joka näyttää veden määrän säiliössä raja-arvoina sekä kosteusarvon
mullassa/maaperässä.

Anturit ovat kytkettynä Arduino mikrokontrolleriin.
Mikrokontrolleria ohjataan ohjelmalla, joka on toteutettu C-ohjelmointikielellä. 

Päälle kytkettynä laite toimii täysin automaattisesti, pois lukien vesisäiliön täyttö.
