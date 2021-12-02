var cy = cytoscape({
  container: document.getElementById('cy'),

  boxSelectionEnabled: false,
  autounselectify: true,

  style: cytoscape.stylesheet()
    .selector('node')
      .style({
        'content': 'data(id)'
      })
    .selector('edge')
      .style({
        'curve-style': 'bezier',
        'target-arrow-shape': 'triangle',
        'width': 4,
        'line-color': '#ddd',
        'target-arrow-color': '#ddd'
      })
    .selector('.highlighted')
      .style({
        'background-color': '#61bffc',
        'line-color': '#61bffc',
        'target-arrow-color': '#61bffc',
        'transition-property': 'background-color, line-color, target-arrow-color',
        'transition-duration': '0.2s'
      }),

  elements: {
      nodes: [
        { data: { id: 'a' } },
        { data: { id: 'b' } },
        { data: { id: 'c' } },
        { data: { id: 'd' } },
        { data: { id: 'e' } },
        { data: { id: 'f' } }
      ],

      edges: [
        { data: { id: 'ab', weight: 2, source: 'a', target: 'b' } },
        { data: { id: 'ae', weight: 2, source: 'a', target: 'e' } },
        { data: { id: 'bc', weight: 2, source: 'b', target: 'c' } },
        { data: { id: 'bf', weight: 2, source: 'b', target: 'f' } },
        { data: { id: 'de', weight: 2, source: 'd', target: 'e' } },
        { data: { id: 'db', weight: 2, source: 'd', target: 'b' } },
        { data: { id: 'ec', weight: 2, source: 'e', target: 'c' } },
        { data: { id: 'ef', weight: 2, source: 'e', target: 'f' } }
      ]
    },

      /*edges: [
        { data: { id: 'ae', weight: 1, source: 'a', target: 'e' } },
        { data: { id: 'ab', weight: 3, source: 'a', target: 'b' } },
        { data: { id: 'be', weight: 4, source: 'b', target: 'e' } },
        { data: { id: 'bc', weight: 5, source: 'b', target: 'c' } },
        { data: { id: 'ce', weight: 6, source: 'c', target: 'e' } },
        { data: { id: 'cd', weight: 2, source: 'c', target: 'd' } },
        { data: { id: 'de', weight: 7, source: 'd', target: 'e' } }
      ]
    },*/

  layout: {
    name: 'breadthfirst',
    directed: true,
    roots: '#h',
    padding: 10
  }
});

var bfs = cy.elements().bfs('#a', function(){}, true);

var i = 0;
var highlightNextEle = function(){
  if( i < bfs.path.length ){
    bfs.path[i].addClass('highlighted');

    i++;
    setTimeout(highlightNextEle, 1000);
  }
};

// kick off first highlight
highlightNextEle();
//***************Código de DP***************************** 
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
//***************Fin Código de DP***************************** 
//*************** Código de FB***************************** 
function MejorRecorrido(linea,estacion,tiempoant){
  tiempoant+=S[linea][estacion];
  if(estacion < 3){
    MejorRecorrido(linea, estacion+1, tiempoant);//Llamada a seguir en la linea
    if(linea==1){
      cambio=MejorRecorrido(0, estacion+1,tiempoant+t[linea][estacion]);
  }else{
      cambio=MejorRecorrido(1, estacion+1,tiempoant+t[linea][estacion]);
  }
    return;
  }
    MR.push(tiempoant+x[linea]);
  return;
}
//***************Fin Código de FB***************************** 
//***************Recepcion de datos del Código de DP***************************** 
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
    }
    //***************Fin de Recepcion de datos del Código de DP***************************** 
//*************** Recepcion de datos del Código de FB***************************** 
    var obtenerdatosFB=function () {
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
  
      e=new Array();
      e.push(entradal1);
      e.push(entradal2);
      x= new Array();
      x.push(salidal1);
      x.push(salidal2);
      S=[[nodo1l1,nodo2l1,nodo3l1,nodo4l1],[nodo1l2,nodo2l2,nodo3l2,nodo4l2]];
      t=[[cambio1l1,cambio2l1,cambio3l1],[cambio1l2,cambio2l2,cambio3l2]];
      MR=new Array();
      index=0;
      MejorRecorrido(0,0,e[0]);
      MejorRecorrido(1,0,e[1]);
      /*document.write(S[0]+"<br>");
      document.write(S[1]+"<br>");
      document.write(t[0]+"<br>");
      document.write(t[1]+"<br>");
      document.write(x+"<br>");
      document.write(e+"<br>");*/
      var min=MR[0];
      for(i=1;i<MR.length;i++){
        if(MR[i]<min){
        min=MR[i];
      }
    }
      document.getElementById("resultado").innerHTML = "El Tiempo total del ensamblado es: "+min;
      //document.write(carAssembleTime(a, t, entrada, salida));
      //console.log(entradal1+" "+nodo1l1+" "+nodo2l1+" "+nodo3l1+" "+nodo4l1+" "+cambio1l1+" "+cambio2l1+" "+cambio3l1+" "+salidal1+" finl1 ");
      //console.log(entradal2+" "+nodo1l2+" "+nodo2l2+" "+nodo3l2+" "+nodo4l2+" "+cambio1l2+" "+cambio2l2+" "+cambio3l2+" "+salidal2);
    }
    //***************Fin de Recepcion de datos del Código de FB***************************** 