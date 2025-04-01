document.addEventListener("DOMContentLoaded", function() {
    // Funcionalidad para el modo oscuro
    const toggleDark = document.getElementById("toggle-dark");

    // Función para activar modo oscuro automáticamente después de las 19:00 (7:00 PM) y antes de las 6:00 AM
    function activarModoOscuroAutomatico() {
        let hora = new Date().getHours();
        if (hora >= 19 || hora < 7) {
            document.body.classList.add("dark-mode");
        } else {
            document.body.classList.remove("dark-mode");
        }
    }

    // Llamamos a la función al cargar la página
    activarModoOscuroAutomatico();

    // Verifica la hora cada minuto (60000 ms) y cambia el tema si es necesario
    setInterval(activarModoOscuroAutomatico, 60000);

    // Permitir cambiar manualmente con el botón
    toggleDark.addEventListener("click", function() {
        document.body.classList.toggle("dark-mode");
    });

    // Funcionalidad de desplazamiento suave para la navegación
    const links = document.querySelectorAll("nav ul li a");

    links.forEach(link => {
        link.addEventListener("click", function(event) {
            event.preventDefault();
            const targetId = this.getAttribute("href").substring(1);
            const targetElement = document.getElementById(targetId);
            
            if (targetElement) {
                window.scrollTo({
                    top: targetElement.offsetTop - 20,
                    behavior: "smooth"
                });
            }
        });
    });
});
