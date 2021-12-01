function carAssembleTime(a , t , e , x) {
  var n = a[0].length;

  // time taken to leave first station in line 1
  var first = e[0] + a[0][0];

  // time taken to leave first station in line 2
  var second = e[1] + a[1][0];

  for (var i = 1; i < n; i++) {
      var up = Math.min(first + a[0][i], second + t[1][i] + a[0][i]),
              down = Math.min(second + a[1][i], first + t[0][i] + a[1][i]);
      first = up;
      second = down;
  }

  first += x[0];
  second += x[1];

  return Math.min(first, second);
  }

var obtenerdatos=function () {
    var entradal1 = parseInt(document.getElementById("entradaL1").value);
    var nodo1l1 = parseInt(document.getElementById("nodo1-1").value);
    var nodo2l1 = parseInt(document.getElementById("nodo1-2").value);
    var nodo3l1 = parseInt(document.getElementById("nodo1-3").value);
    var nodo4l1 = parseInt(document.getElementById("nodo1-4").value);
    var cambio1l1 = parseInt(document.getElementById("cambiol1-l2-1").value);
    var cambio2l1 = parseInt(document.getElementById("cambiol1-l2-2").value);
    var cambio3l1 = parseInt(document.getElementById("cambiol1-l2-3").value);
    var salidal1 = parseInt(document.getElementById("salidaL1").value);

    var entradal2 = parseInt(document.getElementById("entradaL2").value);
    var nodo1l2 = parseInt(document.getElementById("nodo2-1").value);
    var nodo2l2 = parseInt(document.getElementById("nodo2-2").value);
    var nodo3l2 = parseInt(document.getElementById("nodo2-3").value);
    var nodo4l2 = parseInt(document.getElementById("nodo2-4").value);
    var cambio1l2 = parseInt(document.getElementById("cambiol2-l1-1").value);
    var cambio2l2 = parseInt(document.getElementById("cambiol2-l1-2").value);
    var cambio3l2 = parseInt(document.getElementById("cambiol2-l1-3").value);
    var salidal2 = parseInt(document.getElementById("salidaL2").value);

    var entrada=new Array();
    entrada.push(entradal1);
    entrada.push(entradal2);
    var salida= new Array();
    salida.push(salidal1);
    salida.push(salidal2);

    var a=[[nodo1l1,nodo2l1,nodo3l1,nodo4l1],[nodo1l2,nodo2l2,nodo3l2,nodo4l2]];
    var t=[[0,cambio1l1,cambio2l1,cambio3l1],[0,cambio1l2,cambio2l2,cambio3l2]]
    document.getElementById("resultado").innerHTML = "El Tiempo total del ensamblado es: "+carAssembleTime(a, t, entrada, salida);
    //document.write(carAssembleTime(a, t, entrada, salida));
    //console.log(entradal1+" "+nodo1l1+" "+nodo2l1+" "+nodo3l1+" "+nodo4l1+" "+cambio1l1+" "+cambio2l1+" "+cambio3l1+" "+salidal1+" finl1 ");
    //console.log(entradal2+" "+nodo1l2+" "+nodo2l2+" "+nodo3l2+" "+nodo4l2+" "+cambio1l2+" "+cambio2l2+" "+cambio3l2+" "+salidal2);
  }