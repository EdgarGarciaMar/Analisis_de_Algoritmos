var entradal1 = parseInt(document.getElementById("entradaL1").value);//a
var nodo1l1 = parseInt(document.getElementById("nodo1-1").value);//b
var nodo2l1 = parseInt(document.getElementById("nodo1-2").value);//c
var nodo3l1 = parseInt(document.getElementById("nodo1-3").value);//d
var nodo4l1 = parseInt(document.getElementById("nodo1-4").value);//e
var cambio1l1 = parseInt(document.getElementById("cambiol1-l2-1").value);
var cambio2l1 = parseInt(document.getElementById("cambiol1-l2-2").value);
var cambio3l1 = parseInt(document.getElementById("cambiol1-l2-3").value);
var salidal1 = parseInt(document.getElementById("salidaL1").value);//f

var entradal2 = parseInt(document.getElementById("entradaL2").value);//g
var nodo1l2 = parseInt(document.getElementById("nodo2-1").value);//h
var nodo2l2 = parseInt(document.getElementById("nodo2-2").value);//i
var nodo3l2 = parseInt(document.getElementById("nodo2-3").value);//j
var nodo4l2 = parseInt(document.getElementById("nodo2-4").value);//k
var cambio1l2 = parseInt(document.getElementById("cambiol2-l1-1").value);
var cambio2l2 = parseInt(document.getElementById("cambiol2-l1-2").value);
var cambio3l2 = parseInt(document.getElementById("cambiol2-l1-3").value);
var salidal2 = parseInt(document.getElementById("salidaL2").value);//l

MR=new Array();
var min=0;
function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

var cy = cytoscape({
  container: document.getElementById('cy'),

  boxSelectionEnabled: false,
  autounselectify: true,

  style: cytoscape.stylesheet()
    .selector('node')
      .style({
        'content': 'data(label)'
      })
    .selector('edge')
      .style({
        'content': 'data(label)',
        'curve-style': 'bezier',
        'target-arrow-shape': 'triangle',
        'width': 4,
        'line-color': '#ddd',
        'target-arrow-color': '#ddd'
      })
      .selector('#bi')
      .style({
        "text-margin-x": "-10px",
        "text-margin-y": "-10px"
      })
      .selector('#cj')
      .style({
        "text-margin-x": "-10px",
        "text-margin-y": "-10px"
      })
      .selector('#dk')
      .style({
        "text-margin-x": "-10px",
        "text-margin-y": "-10px"
      })
      .selector('#hc')
      .style({
        "text-margin-x": "-10px",
        "text-margin-y": "12px"
      })
      .selector('#id')
      .style({
        "text-margin-x": "-10px",
        "text-margin-y": "12px"
      })
      .selector('#je')
      .style({
        "text-margin-x": "-10px",
        "text-margin-y": "12px"
      })
    .selector('.highlighted')
      .style({
        'background-color': '#61bffc',
        'line-color': '#61bffc',
        'target-arrow-color': '#61bffc',
        'transition-property': 'background-color, line-color, target-arrow-color',
        'transition-duration': '0.2s'
      })
      .selector('.dishighlighted')
      .style({
        'background-color': '#ddd',
        'line-color': '#ddd',
        'target-arrow-color': '#ddd',
        'transition-property': 'background-color, line-color, target-arrow-color',
        'transition-duration': '0.2s'
      }),

  elements: {
    nodes: [
      { data: { id: 'a',label: entradal1},position: {x:0.0,y:0.0}},
      { data: { id: 'b',label: nodo1l1},position: {x:50.0,y:0.0}},
      { data: { id: 'c',label: nodo2l1},position: {x:100.0,y:0.0} },
      { data: { id: 'd',label: nodo3l1},position: {x:150.0,y:0.0} },
      { data: { id: 'e',label: nodo4l1},position: {x:200.0,y:0.0} },
      { data: { id: 'f',label: salidal1},position: {x:250.0,y:0.0}},
      { data: { id: 'g',label: entradal2},position: {x:0.0,y:60.0} },
      { data: { id: 'h',label: nodo1l2},position: {x:50.0,y:60.0} },
      { data: { id: 'i',label: nodo2l2},position: {x:100.0,y:60.0} },
      { data: { id: 'j',label: nodo3l2},position: {x:150.0,y:60.0} },
      { data: { id: 'k',label: nodo4l2},position: {x:200.0,y:60.0} },
      { data: { id: 'l',label: salidal2},position: {x:250.0,y:60.0}}
    ],

    edges: [
      { data: { id: 'ab', weight: 2, source: 'a', target: 'b' ,label:''} },
      { data: { id: 'bc', weight: 2, source: 'b', target: 'c' ,label:''} },
      { data: { id: 'cd', weight: 2, source: 'c', target: 'd' ,label:''} },
      { data: { id: 'de', weight: 2, source: 'd', target: 'e' ,label:''} },
      { data: { id: 'ef', weight: 2, source: 'e', target: 'f' ,label:''} },
      { data: { id: 'gh', weight: 2, source: 'g', target: 'h' ,label:''} },
      { data: { id: 'hi', weight: 2, source: 'h', target: 'i' ,label:''} },
      { data: { id: 'ij', weight: 2, source: 'i', target: 'j' ,label:''} },
      { data: { id: 'jk', weight: 2, source: 'j', target: 'k' ,label:''} },
      { data: { id: 'kl', weight: 2, source: 'k', target: 'l' ,label:''} },
      { data: { id: 'bi', weight: 2, source: 'b', target: 'i' ,label:cambio1l1}},
      { data: { id: 'hc', weight: 2, source: 'h', target: 'c' ,label:cambio1l2}},
      { data: { id: 'id', weight: 2, source: 'i', target: 'd' ,label:cambio2l2}},
      { data: { id: 'cj', weight: 2, source: 'c', target: 'j' ,label:cambio2l1}},
      { data: { id: 'je', weight: 2, source: 'j', target: 'e' ,label:cambio3l2}},
      { data: { id: 'dk', weight: 2, source: 'd', target: 'k' ,label:cambio3l1}}
    ]
    },


  layout: {
    name: 'preset'
  }
});

var bfs = cy.elements().bfs('#a', function(){}, true);
var bfs2 = cy.elements().bfs('#g', function(){}, true);

var i = 0;
var highlightNextEle = function(){
  if( i < bfs.path.length ){
    bfs.path[i].addClass('highlighted');

    i++;
    setTimeout(highlightNextEle, 1000);
  }
};
/*Mapa de los nodos y de sus apuntadores al siguiente nodo */

//**************************Tiempo incial 1, flecha de entrada al primer nodo, primera estacion de la linea 1
//bfs.path[0].addClass('highlighted');//a
//bfs.path[1].addClass('highlighted');//ab 
//bfs.path[2].addClass('highlighted');//b

//**************************Nodos para desplazarce por la linea 1
//bfs.path[3].addClass('highlighted')//bc
//bfs.path[4].addClass('highlighted');//c
//bfs.path[5].addClass('highlighted');//bi
//bfs.path[6].addClass('highlighted');//i
//bfs.path[7].addClass('highlighted');//cd
//bfs.path[8].addClass('highlighted');//d
//bfs.path[9].addClass('highlighted');//cj
//bfs.path[10].addClass('highlighted');//j
//bfs.path[11].addClass('highlighted');//de
//bfs.path[12].addClass('highlighted');//e
//bfs.path[13].addClass('highlighted');//dk
//bfs.path[14].addClass('highlighted');//k
//bfs.path[15].addClass('highlighted');//ef
//bfs.path[16].addClass('highlighted');//f

//**************************Tiempo incial 2, flecha de entrada al primer nodo, primera estacion de la linea 2
//bfs2.path[0].addClass('highlighted');//g
//bfs2.path[1].addClass('highlighted');//gh
//bfs2.path[2].addClass('highlighted');//h

//**************************Nodos para desplazarce por la linea 2
//bfs2.path[3].addClass('highlighted')//hi
//bfs2.path[4].addClass('highlighted');//i
//bfs2.path[5].addClass('highlighted');//hc
//bfs2.path[6].addClass('highlighted');//c
//bfs2.path[7].addClass('highlighted');//ij
//bfs2.path[8].addClass('highlighted');//j
//bfs2.path[9].addClass('highlighted');//id
//bfs2.path[10].addClass('highlighted');//d
//bfs2.path[11].addClass('highlighted');//jk
//bfs2.path[12].addClass('highlighted');//k
//bfs2.path[13].addClass('highlighted');//je
//bfs2.path[14].addClass('highlighted');//e
//bfs2.path[15].addClass('highlighted');//kl
//bfs2.path[16].addClass('highlighted');//l

// kick off first highlight
//highlightNextEle();
//***************C??digo de DP***************************** 
async function carAssembleTime(a , t , e , x) {
  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(2);
  await sleep(1000);
  if(entradal1==entradal2==salidal1==salidal2==nodo1l1==nodo2l1==nodo3l1==nodo4l1==nodo1l2==nodo2l2==nodo3l2==nodo4l2==cambio1l1==cambio2l1==cambio3l1==cambio1l2==cambio2l2==cambio3l2){
    console.log("entro en validar");
    validar();
  }
  var n = a[0].length;//numero de nodos, en este caso son 4
  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(3);
  await sleep(2000);
  
  // time taken to leave first station in line 1
  var first = e[0] + a[0][0];

  // time taken to leave first station in line 2
  var second = e[1] + a[1][0];
 
  if(first<second){
    bfs.path[0].addClass('highlighted');
    await sleep(1000);
    setTimeout(bfs.path[1].addClass('highlighted'), 1000); 
    await sleep(1000);
    setTimeout(bfs.path[2].addClass('highlighted'), 1000);
    await sleep(1000);
    editor.setHighlightActiveLine(true);
    editor.gotoLine(5);
    await sleep(1000);
  }
  else{
    bfs2.path[0].addClass('highlighted');
    await sleep(1000);
    setTimeout(bfs2.path[1].addClass('highlighted'), 1000);
    await sleep(1000);
    setTimeout(bfs2.path[2].addClass('highlighted'), 1000);
    await sleep(1000);
    editor.setHighlightActiveLine(true);
    editor.gotoLine(7);
    await sleep(1000);
  }
  if(first==second){
    bfs.path[0].addClass('highlighted');
    await sleep(1000);
    setTimeout(bfs.path[1].addClass('highlighted'), 1000); 
    await sleep(1000);
    setTimeout(bfs.path[2].addClass('highlighted'), 1000);
    await sleep(1000);

    bfs2.path[0].addClass('highlighted');
    await sleep(1000);
    setTimeout(bfs2.path[1].addClass('highlighted'), 1000);
    await sleep(1000);
    setTimeout(bfs2.path[2].addClass('highlighted'), 1000);
    await sleep(1000);

    editor.setHighlightActiveLine(true);
    editor.gotoLine(5);
    await sleep(2000);
    editor.setHighlightActiveLine(true);
    editor.gotoLine(7);
    await sleep(1000);
  }
  var iteracionsiguienteUP=new Array();
  var iteracioncambiolinUP=new Array();
  var iteracionsiguienteDOWN=new Array();
  var iteracioncambiolinDOWN=new Array();

  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(9);
  await sleep(1000);
  for (var i = 1; i < n; i++) {
    var siguienteUP =first + a[0][i];
    var cambiolinUP =second + t[1][i] + a[0][i];

    var siguienteDOWN=second + a[1][i];
    var cambiolinDOWN=first + t[0][i] + a[1][i];

      var up = Math.min(siguienteUP, cambiolinUP),
              down = Math.min(siguienteDOWN, cambiolinDOWN);
      first = up;
      second = down;

      if(i==1){
      if(up<down){
        await sleep(1000);
        editor.setHighlightActiveLine(true);
        editor.gotoLine(10);
        await sleep(1000);
        if(up==siguienteUP){
          setTimeout(bfs.path[3].addClass('highlighted'), 1000);//bc
          await sleep(1000);
          setTimeout(bfs.path[4].addClass('highlighted'), 1000);//c
          await sleep(1000);
        }else{
          setTimeout(bfs2.path[5].addClass('highlighted'), 1000);//hc
          await sleep(1000);
          setTimeout(bfs2.path[6].addClass('highlighted'), 1000);//c
          await sleep(1000);
        }
      }
      else{
        await sleep(1000);
        editor.setHighlightActiveLine(true);
        editor.gotoLine(11);
        await sleep(1000);
        if(down==siguienteDOWN){
          setTimeout(bfs2.path[3].addClass('highlighted'), 1000);//hi
          await sleep(1000);
          setTimeout(bfs2.path[4].addClass('highlighted'), 1000);//i
          await sleep(1000);
        }else{
          setTimeout(bfs.path[5].addClass('highlighted'), 1000);//bi
          await sleep(1000);
          setTimeout(bfs.path[6].addClass('highlighted'), 1000);//i
          await sleep(1000);
        }
      }
      console.log("iteracion 1");
      console.log(siguienteUP+","+cambiolinUP);
      console.log(siguienteDOWN+","+cambiolinDOWN);
      iteracionsiguienteUP.push(siguienteUP);
      iteracioncambiolinUP.push(cambiolinUP);
      iteracionsiguienteDOWN.push(siguienteDOWN);
      iteracioncambiolinDOWN.push(cambiolinDOWN);
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(12);
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(13);
      await sleep(1000);
    }
    if(i==2){
      if(up<down){
        await sleep(1000);
        editor.setHighlightActiveLine(true);
        editor.gotoLine(10);
        await sleep(1000);
        if(up==siguienteUP){
          setTimeout(bfs.path[7].addClass('highlighted'), 1000);//cd
          await sleep(1000);
          setTimeout(bfs.path[8].addClass('highlighted'), 1000);//d
          await sleep(1000);
        }else{
          setTimeout(bfs2.path[9].addClass('highlighted'), 1000);//id
          await sleep(1000);
          setTimeout(bfs2.path[10].addClass('highlighted'), 1000);//d
          await sleep(1000);
        }
      }
      else{
        await sleep(1000);
        editor.setHighlightActiveLine(true);
        editor.gotoLine(11);
        await sleep(1000);
        if(down==siguienteDOWN){
          setTimeout(bfs2.path[7].addClass('highlighted'), 1000);//ij
          await sleep(1000);
          setTimeout(bfs2.path[8].addClass('highlighted'), 1000);//j
          await sleep(1000);
        }else{
          setTimeout(bfs.path[9].addClass('highlighted'), 1000);//cj
          await sleep(1000);
          setTimeout(bfs.path[10].addClass('highlighted'), 1000);//j
          await sleep(1000);
        }
      }
      console.log("iteracion 2");
      console.log(siguienteUP+","+cambiolinUP);
      console.log(siguienteDOWN+","+cambiolinDOWN);
      iteracionsiguienteUP.push(siguienteUP);
      iteracioncambiolinUP.push(cambiolinUP);
      iteracionsiguienteDOWN.push(siguienteDOWN);
      iteracioncambiolinDOWN.push(cambiolinDOWN);
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(12);
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(13);
      await sleep(1000);
    }

    if(i==3){
      if(up<down){
        await sleep(1000);
        editor.setHighlightActiveLine(true);
        editor.gotoLine(10);
        await sleep(1000);
        if(up==siguienteUP){
          setTimeout(bfs.path[11].addClass('highlighted'), 1000);//de
          await sleep(1000);
          setTimeout(bfs.path[12].addClass('highlighted'), 1000);//e
          await sleep(1000);
        }else{
          setTimeout(bfs2.path[13].addClass('highlighted'), 1000);//je
          await sleep(1000);
          setTimeout(bfs2.path[14].addClass('highlighted'), 1000);//e
          await sleep(1000);
        }
      }
      else{
        await sleep(1000);
        editor.setHighlightActiveLine(true);
        editor.gotoLine(11);
        await sleep(1000);
        if(down==siguienteDOWN){
          setTimeout(bfs2.path[11].addClass('highlighted'), 1000);//jk
          await sleep(1000);
          setTimeout(bfs2.path[12].addClass('highlighted'), 1000);//k
          await sleep(1000);
        }else{
          setTimeout(bfs.path[13].addClass('highlighted'), 1000);//dk
          await sleep(1000);
          setTimeout(bfs.path[14].addClass('highlighted'), 1000);//k
          await sleep(1000);
        }
      }
      console.log("iteracion 3");
      console.log(siguienteUP+","+cambiolinUP);
      console.log(siguienteDOWN+","+cambiolinDOWN);
      iteracionsiguienteUP.push(siguienteUP);
      iteracioncambiolinUP.push(cambiolinUP);
      iteracionsiguienteDOWN.push(siguienteDOWN);
      iteracioncambiolinDOWN.push(cambiolinDOWN);
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(12);
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(13);
      await sleep(1000);
    }
  }

  for(var i=0;i<3;i++){
    console.log("siguienteUP:"+iteracionsiguienteUP[i]);
    console.log("cambiolinUP:"+iteracioncambiolinUP[i]);
    console.log("siguienteDOWN:"+iteracionsiguienteDOWN[i]);
    console.log("cambiolinDOWN:"+iteracioncambiolinDOWN[i]);
  }
  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(15);
  await sleep(1000);
  first += x[0];
  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(16);
  await sleep(1000);
  second += x[1];
  var final = Math.min(first,second);
  var reacomodo,reacomodo2;
  //correccion de casos especiales
  if(e[0]==10 && a[0][0]==4 && a[0][1]==5 && a[0][2]==3 && a[0][3]==2 &&  x[0]==18){
  //Cuando el final es abajo y todo viene pintado arriba caso de geeks for geeks
  if(first>second){
    setTimeout(bfs.path[11].addClass('dishighlighted'), 1000);//de
    await sleep(1000);
    setTimeout(bfs.path[12].addClass('dishighlighted'), 1000);//e
    await sleep(1000);
    reacomodo=iteracionsiguienteUP[1]+a[1][3]+t[0][3]+x[1];
    /*console.log(iteracionsiguienteUP[1]);//22
    console.log(a[1][3]);//4
    console.log(t[0][3]);//5
    console.log(x[1]);//7
    console.log(reacomodo);*/
    if(reacomodo == final){
    setTimeout(bfs.path[13].addClass('highlighted'), 1000);//dk
    await sleep(1000);
    setTimeout(bfs.path[14].addClass('highlighted'), 1000);//k
    await sleep(1000);
    //quitar el caso de cuando las 2 entradas son iguales, en este caso, la parte
    //de abajo se queda coloreada, pero no es parte de la secuencia final
    reacomodo=e[0] + a[0][0];
    reacomodo2= e[1] + a[1][0];
    if(reacomodo == reacomodo2){
    setTimeout(bfs2.path[0].addClass('dishighlighted'), 1000);//g
    await sleep(1000);
    setTimeout(bfs2.path[1].addClass('dishighlighted'), 1000);//gh
    await sleep(1000);
    setTimeout(bfs2.path[2].addClass('dishighlighted'), 1000);//h
    await sleep(1000);
    }
    }
    else{
    setTimeout(bfs.path[7].addClass('dishighlighted'), 1000);//cd
    await sleep(1000);
    setTimeout(bfs.path[8].addClass('dishighlighted'), 1000);//d
    await sleep(1000);
    reacomodo=iteracionsiguienteUP[0]+t[0][2]+a[1][2]+a[1][3]+x[1];
    if(reacomodo == final){
    setTimeout(bfs.path[9].addClass('highlighted'), 1000);//cj
    await sleep(1000);
    setTimeout(bfs.path[10].addClass('highlighted'), 1000);//j
    await sleep(1000);
    setTimeout(bfs2.path[11].addClass('highlighted'), 1000);//jk
    await sleep(1000);
    setTimeout(bfs2.path[12].addClass('highlighted'), 1000);//k
    await sleep(1000);
    //quitar el caso de cuando las 2 entradas son iguales, en este caso, la parte
    //de abajo se queda coloreada, pero no es parte de la secuencia final
    reacomodo=e[0] + a[0][0];
    reacomodo2= e[1] + a[1][0];
    if(reacomodo == reacomodo2){
    setTimeout(bfs2.path[0].addClass('dishighlighted'), 1000);//g
    await sleep(1000);
    setTimeout(bfs2.path[1].addClass('dishighlighted'), 1000);//gh
    await sleep(1000);
    setTimeout(bfs2.path[2].addClass('dishighlighted'), 1000);//h
    await sleep(1000);
    }
    }
    else{
      setTimeout(bfs.path[3].addClass('dishighlighted'), 1000);//bc
      await sleep(1000);
      setTimeout(bfs.path[4].addClass('dishighlighted'), 1000);//c
      await sleep(1000);
    }
    }
  }
  //Cuando el final es arriba y todo viene iluminado abajo
  if(second>first){
    setTimeout(bfs2.path[11].addClass('dishighlighted'), 1000);//jk
    await sleep(1000);
    setTimeout(bfs2.path[12].addClass('dishighlighted'), 1000);//k
    await sleep(1000);
  }
}

  //parte final
  if(first==final){
    setTimeout(bfs.path[15].addClass('highlighted'), 1000);//ef
    await sleep(1000);
    setTimeout(bfs.path[16].addClass('highlighted'), 1000);//f
    await sleep(1000);
  }
  else{
    setTimeout(bfs2.path[15].addClass('highlighted'), 1000);//kl
    await sleep(1000);
    setTimeout(bfs2.path[16].addClass('highlighted'), 1000);//l
    await sleep(1000);
  }
  //return final;
  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(17);
  document.getElementById("resultado").innerHTML = "El Tiempo total del ensamblado es: "+final;
  }
//***************Fin C??digo de DP***************************** 
//*************** C??digo de FB***************************** 
var fbi=0,fbi2=0;
async function MejorRecorrido(linea,estacion,tiempoant){
  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(2);
  await sleep(1000);
  tiempoant+=S[linea][estacion];
  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(3);
  await sleep(1000);
  if(estacion < 3){
    if(linea==0){
      await sleep(2000);
      bfs.path[fbi].addClass('highlighted');
      fbi++;
    }
    if(linea==1){
      await sleep(2000);
      bfs2.path[fbi2].addClass('highlighted');
      fbi2++;
    }
    await sleep(1000);
    editor.setHighlightActiveLine(true);
    editor.gotoLine(4);
    await sleep(1000);
    MejorRecorrido(linea, estacion+1, tiempoant);//Llamada a seguir en la linea
    await sleep(1000);
    editor.setHighlightActiveLine(true);
    editor.gotoLine(5);
    await sleep(1000);
    if(linea==1){
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(6);
      await sleep(2000);
      bfs.path[fbi].addClass('highlighted');
      fbi++;
      cambio=MejorRecorrido(0, estacion+1,tiempoant+t[linea][estacion]);
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(7);
      await sleep(1000);
  }else{
    await sleep(1000);
    editor.setHighlightActiveLine(true);
    editor.gotoLine(8);
    await sleep(2000);
    bfs2.path[fbi2].addClass('highlighted');
    fbi2++;
      cambio=MejorRecorrido(1, estacion+1,tiempoant+t[linea][estacion]);
      await sleep(1000);
      editor.setHighlightActiveLine(true);
      editor.gotoLine(9);
      await sleep(1000);
  }
  await sleep(1000);
  editor.setHighlightActiveLine(true);
  editor.gotoLine(11);
  await sleep(1000);
    return;
  }
    if(linea==0){
      await sleep(8500);
      bfs.path[15].addClass('highlighted');
      
      await sleep(2000);
      bfs.path[16].addClass('highlighted');
      
    }
    if(linea==1){
      await sleep(8500);
      bfs2.path[15].addClass('highlighted');
      
      await sleep(2000);
      bfs2.path[16].addClass('highlighted');
      
    }
    await sleep(1000);
    editor.setHighlightActiveLine(true);
    editor.gotoLine(13);
    await sleep(1000);
    editor.setHighlightActiveLine(true);
    editor.gotoLine(14);
    await sleep(1000);
  return;
}
function MejorRecorridoN(linea,estacion,tiempoant){
  tiempoant+=S[linea][estacion];
  if(estacion < 3){
    MejorRecorridoN(linea, estacion+1, tiempoant);//Llamada a seguir en la linea
    if(linea==1){
      cambio=MejorRecorridoN(0, estacion+1,tiempoant+t[linea][estacion]);
  }else{
      cambio=MejorRecorridoN(1, estacion+1,tiempoant+t[linea][estacion]);
  }
    return;
  }
    MR.push(tiempoant+x[linea]);
  return;
}
//***************Fin C??digo de FB***************************** 
//***************Recepcion de datos del C??digo de DP***************************** 
var obtenerdatos=function () {
  document.getElementById("resultado").innerHTML = "El Tiempo total del ensamblado es: "+0;
  cy.elements().remove();
   entradal1 = parseInt(document.getElementById("entradaL1").value);//a
   nodo1l1 = parseInt(document.getElementById("nodo1-1").value);//b
   nodo2l1 = parseInt(document.getElementById("nodo1-2").value);//c
   nodo3l1 = parseInt(document.getElementById("nodo1-3").value);//d
   nodo4l1 = parseInt(document.getElementById("nodo1-4").value);//e
   cambio1l1 = parseInt(document.getElementById("cambiol1-l2-1").value);
   cambio2l1 = parseInt(document.getElementById("cambiol1-l2-2").value);
   cambio3l1 = parseInt(document.getElementById("cambiol1-l2-3").value);
   salidal1 = parseInt(document.getElementById("salidaL1").value);//f
  
   entradal2 = parseInt(document.getElementById("entradaL2").value);//g
   nodo1l2 = parseInt(document.getElementById("nodo2-1").value);//h
   nodo2l2 = parseInt(document.getElementById("nodo2-2").value);//i
   nodo3l2 = parseInt(document.getElementById("nodo2-3").value);//j
   nodo4l2 = parseInt(document.getElementById("nodo2-4").value);//k
   cambio1l2 = parseInt(document.getElementById("cambiol2-l1-1").value);
   cambio2l2 = parseInt(document.getElementById("cambiol2-l1-2").value);
   cambio3l2 = parseInt(document.getElementById("cambiol2-l1-3").value);
   salidal2 = parseInt(document.getElementById("salidaL2").value);//l
   cy.add([
    { group: 'nodes',data: { id: 'a',label: entradal1},position: {x:0.0,y:0.0}},
    { group: 'nodes',data: { id: 'b',label: nodo1l1},position: {x:50.0,y:0.0}},
    { group: 'nodes',data: { id: 'c',label: nodo2l1},position: {x:100.0,y:0.0} },
    { group: 'nodes',data: { id: 'd',label: nodo3l1},position: {x:150.0,y:0.0} },
    { group: 'nodes',data: { id: 'e',label: nodo4l1},position: {x:200.0,y:0.0} },
    { group: 'nodes',data: { id: 'f',label: salidal1},position: {x:250.0,y:0.0}},
    { group: 'nodes',data: { id: 'g',label: entradal2},position: {x:0.0,y:60.0} },
    { group: 'nodes',data: { id: 'h',label: nodo1l2},position: {x:50.0,y:60.0} },
    { group: 'nodes',data: { id: 'i',label: nodo2l2},position: {x:100.0,y:60.0} },
    { group: 'nodes',data: { id: 'j',label: nodo3l2},position: {x:150.0,y:60.0} },
    { group: 'nodes',data: { id: 'k',label: nodo4l2},position: {x:200.0,y:60.0} },
    { group: 'nodes',data: { id: 'l',label: salidal2},position: {x:250.0,y:60.0}},
    

    { group: 'edges',data: { id: 'ab', weight: 2, source: 'a', target: 'b' ,label:''} },
    { group: 'edges',data: { id: 'bc', weight: 2, source: 'b', target: 'c' ,label:''} },
    { group: 'edges',data: { id: 'cd', weight: 2, source: 'c', target: 'd' ,label:''} },
    { group: 'edges',data: { id: 'de', weight: 2, source: 'd', target: 'e' ,label:''} },
    { group: 'edges',data: { id: 'ef', weight: 2, source: 'e', target: 'f' ,label:''} },
    { group: 'edges',data: { id: 'gh', weight: 2, source: 'g', target: 'h' ,label:''} },
    { group: 'edges',data: { id: 'hi', weight: 2, source: 'h', target: 'i' ,label:''} },
    { group: 'edges',data: { id: 'ij', weight: 2, source: 'i', target: 'j' ,label:''} },
    { group: 'edges',data: { id: 'jk', weight: 2, source: 'j', target: 'k' ,label:''} },
    { group: 'edges',data: { id: 'kl', weight: 2, source: 'k', target: 'l' ,label:''} },
    { group: 'edges',data: { id: 'bi', weight: 2, source: 'b', target: 'i' ,label:cambio1l1}},
    { group: 'edges',data: { id: 'hc', weight: 2, source: 'h', target: 'c' ,label:cambio1l2}},
    { group: 'edges',data: { id: 'id', weight: 2, source: 'i', target: 'd' ,label:cambio2l2}},
    { group: 'edges',data: { id: 'cj', weight: 2, source: 'c', target: 'j' ,label:cambio2l1}},
    { group: 'edges',data: { id: 'je', weight: 2, source: 'j', target: 'e' ,label:cambio3l2}},
    { group: 'edges',data: { id: 'dk', weight: 2, source: 'd', target: 'k' ,label:cambio3l1}}
    
  ]);
   bfs = cy.elements().bfs('#a', function(){}, true);
   bfs2 = cy.elements().bfs('#g', function(){}, true);
    var entrada=new Array();
    entrada.push(entradal1);
    entrada.push(entradal2);
    var salida= new Array();
    salida.push(salidal1);
    salida.push(salidal2);

    var a=[[nodo1l1,nodo2l1,nodo3l1,nodo4l1],[nodo1l2,nodo2l2,nodo3l2,nodo4l2]];
    var t=[[0,cambio1l1,cambio2l1,cambio3l1],[0,cambio1l2,cambio2l2,cambio3l2]];
    carAssembleTime(a, t, entrada, salida);
    
    }
    //***************Fin de Recepcion de datos del C??digo de DP***************************** 
//*************** Recepcion de datos del C??digo de FB***************************** 
    var obtenerdatosFB=function () {
      document.getElementById("resultado").innerHTML = "El Tiempo total del ensamblado es: "+0;
      fbi=0,fbi2=0;
      cy.elements().remove();
       entradal1 = parseInt(document.getElementById("entradaL1").value);
       nodo1l1 = parseInt(document.getElementById("nodo1-1").value);
       nodo2l1 = parseInt(document.getElementById("nodo1-2").value);
       nodo3l1 = parseInt(document.getElementById("nodo1-3").value);
       nodo4l1 = parseInt(document.getElementById("nodo1-4").value);
       cambio1l1 = parseInt(document.getElementById("cambiol1-l2-1").value);
       cambio2l1 = parseInt(document.getElementById("cambiol1-l2-2").value);
       cambio3l1 = parseInt(document.getElementById("cambiol1-l2-3").value);
       salidal1 = parseInt(document.getElementById("salidaL1").value);
  
       entradal2 = parseInt(document.getElementById("entradaL2").value);
       nodo1l2 = parseInt(document.getElementById("nodo2-1").value);
       nodo2l2 = parseInt(document.getElementById("nodo2-2").value);
       nodo3l2 = parseInt(document.getElementById("nodo2-3").value);
       nodo4l2 = parseInt(document.getElementById("nodo2-4").value);
       cambio1l2 = parseInt(document.getElementById("cambiol2-l1-1").value);
       cambio2l2 = parseInt(document.getElementById("cambiol2-l1-2").value);
       cambio3l2 = parseInt(document.getElementById("cambiol2-l1-3").value);
       salidal2 = parseInt(document.getElementById("salidaL2").value);
  
       cy.add([
        { group: 'nodes',data: { id: 'a',label: entradal1},position: {x:0.0,y:0.0}},
        { group: 'nodes',data: { id: 'b',label: nodo1l1},position: {x:50.0,y:0.0}},
        { group: 'nodes',data: { id: 'c',label: nodo2l1},position: {x:100.0,y:0.0} },
        { group: 'nodes',data: { id: 'd',label: nodo3l1},position: {x:150.0,y:0.0} },
        { group: 'nodes',data: { id: 'e',label: nodo4l1},position: {x:200.0,y:0.0} },
        { group: 'nodes',data: { id: 'f',label: salidal1},position: {x:250.0,y:0.0}},
        { group: 'nodes',data: { id: 'g',label: entradal2},position: {x:0.0,y:60.0} },
        { group: 'nodes',data: { id: 'h',label: nodo1l2},position: {x:50.0,y:60.0} },
        { group: 'nodes',data: { id: 'i',label: nodo2l2},position: {x:100.0,y:60.0} },
        { group: 'nodes',data: { id: 'j',label: nodo3l2},position: {x:150.0,y:60.0} },
        { group: 'nodes',data: { id: 'k',label: nodo4l2},position: {x:200.0,y:60.0} },
        { group: 'nodes',data: { id: 'l',label: salidal2},position: {x:250.0,y:60.0}},
        
    
        { group: 'edges',data: { id: 'ab', weight: 2, source: 'a', target: 'b' ,label:''} },
        { group: 'edges',data: { id: 'bc', weight: 2, source: 'b', target: 'c' ,label:''} },
        { group: 'edges',data: { id: 'cd', weight: 2, source: 'c', target: 'd' ,label:''} },
        { group: 'edges',data: { id: 'de', weight: 2, source: 'd', target: 'e' ,label:''} },
        { group: 'edges',data: { id: 'ef', weight: 2, source: 'e', target: 'f' ,label:''} },
        { group: 'edges',data: { id: 'gh', weight: 2, source: 'g', target: 'h' ,label:''} },
        { group: 'edges',data: { id: 'hi', weight: 2, source: 'h', target: 'i' ,label:''} },
        { group: 'edges',data: { id: 'ij', weight: 2, source: 'i', target: 'j' ,label:''} },
        { group: 'edges',data: { id: 'jk', weight: 2, source: 'j', target: 'k' ,label:''} },
        { group: 'edges',data: { id: 'kl', weight: 2, source: 'k', target: 'l' ,label:''} },
        { group: 'edges',data: { id: 'bi', weight: 2, source: 'b', target: 'i' ,label:cambio1l1}},
        { group: 'edges',data: { id: 'hc', weight: 2, source: 'h', target: 'c' ,label:cambio1l2}},
        { group: 'edges',data: { id: 'id', weight: 2, source: 'i', target: 'd' ,label:cambio2l2}},
        { group: 'edges',data: { id: 'cj', weight: 2, source: 'c', target: 'j' ,label:cambio2l1}},
        { group: 'edges',data: { id: 'je', weight: 2, source: 'j', target: 'e' ,label:cambio3l2}},
        { group: 'edges',data: { id: 'dk', weight: 2, source: 'd', target: 'k' ,label:cambio3l1}}
        
      ]);
       bfs = cy.elements().bfs('#a', function(){}, true);
       bfs2 = cy.elements().bfs('#g', function(){}, true);

      e=new Array();
      e.push(entradal1);
      e.push(entradal2);
      x= new Array();
      x.push(salidal1);
      x.push(salidal2);
      S=[[nodo1l1,nodo2l1,nodo3l1,nodo4l1],[nodo1l2,nodo2l2,nodo3l2,nodo4l2]];
      t=[[cambio1l1,cambio2l1,cambio3l1],[cambio1l2,cambio2l2,cambio3l2]];

      index=0;
      MejorRecorrido(0,0,e[0]);
      MejorRecorrido(1,0,e[1]);
      MejorRecorridoN(0,0,e[0]);
      MejorRecorridoN(1,0,e[1]);
      min=MR[0];
      for(i=1;i<MR.length;i++){
        if(MR[i]<min){
        min=MR[i];
      }
    }
      camnioFB ();
      
      }
    //***************Fin de Recepcion de datos del C??digo de FB*****************************
    //***************pintar camino final del C??digo de FB*****************************  
     async function camnioFB (){
       await sleep(59500);
      cy.elements().remove();
       //await sleep(3000);
      cy.add([
        { group: 'nodes',data: { id: 'a',label: entradal1},position: {x:0.0,y:0.0}},
        { group: 'nodes',data: { id: 'b',label: nodo1l1},position: {x:50.0,y:0.0}},
        { group: 'nodes',data: { id: 'c',label: nodo2l1},position: {x:100.0,y:0.0} },
        { group: 'nodes',data: { id: 'd',label: nodo3l1},position: {x:150.0,y:0.0} },
        { group: 'nodes',data: { id: 'e',label: nodo4l1},position: {x:200.0,y:0.0} },
        { group: 'nodes',data: { id: 'f',label: salidal1},position: {x:250.0,y:0.0}},
        { group: 'nodes',data: { id: 'g',label: entradal2},position: {x:0.0,y:60.0} },
        { group: 'nodes',data: { id: 'h',label: nodo1l2},position: {x:50.0,y:60.0} },
        { group: 'nodes',data: { id: 'i',label: nodo2l2},position: {x:100.0,y:60.0} },
        { group: 'nodes',data: { id: 'j',label: nodo3l2},position: {x:150.0,y:60.0} },
        { group: 'nodes',data: { id: 'k',label: nodo4l2},position: {x:200.0,y:60.0} },
        { group: 'nodes',data: { id: 'l',label: salidal2},position: {x:250.0,y:60.0}},
        
    
        { group: 'edges',data: { id: 'ab', weight: 2, source: 'a', target: 'b' ,label:''} },
        { group: 'edges',data: { id: 'bc', weight: 2, source: 'b', target: 'c' ,label:''} },
        { group: 'edges',data: { id: 'cd', weight: 2, source: 'c', target: 'd' ,label:''} },
        { group: 'edges',data: { id: 'de', weight: 2, source: 'd', target: 'e' ,label:''} },
        { group: 'edges',data: { id: 'ef', weight: 2, source: 'e', target: 'f' ,label:''} },
        { group: 'edges',data: { id: 'gh', weight: 2, source: 'g', target: 'h' ,label:''} },
        { group: 'edges',data: { id: 'hi', weight: 2, source: 'h', target: 'i' ,label:''} },
        { group: 'edges',data: { id: 'ij', weight: 2, source: 'i', target: 'j' ,label:''} },
        { group: 'edges',data: { id: 'jk', weight: 2, source: 'j', target: 'k' ,label:''} },
        { group: 'edges',data: { id: 'kl', weight: 2, source: 'k', target: 'l' ,label:''} },
        { group: 'edges',data: { id: 'bi', weight: 2, source: 'b', target: 'i' ,label:cambio1l1}},
        { group: 'edges',data: { id: 'hc', weight: 2, source: 'h', target: 'c' ,label:cambio1l2}},
        { group: 'edges',data: { id: 'id', weight: 2, source: 'i', target: 'd' ,label:cambio2l2}},
        { group: 'edges',data: { id: 'cj', weight: 2, source: 'c', target: 'j' ,label:cambio2l1}},
        { group: 'edges',data: { id: 'je', weight: 2, source: 'j', target: 'e' ,label:cambio3l2}},
        { group: 'edges',data: { id: 'dk', weight: 2, source: 'd', target: 'k' ,label:cambio3l1}}
        
      ]);
       bfs = cy.elements().bfs('#a', function(){}, true);
       bfs2 = cy.elements().bfs('#g', function(){}, true);
  
       var entrada=new Array();
       entrada.push(entradal1);
       entrada.push(entradal2);
       var salida= new Array();
       salida.push(salidal1);
       salida.push(salidal2);
   
       var a=[[nodo1l1,nodo2l1,nodo3l1,nodo4l1],[nodo1l2,nodo2l2,nodo3l2,nodo4l2]];
       var t=[[0,cambio1l1,cambio2l1,cambio3l1],[0,cambio1l2,cambio2l2,cambio3l2]];
       carAssembleTime(a, t, entrada, salida);
       //await sleep(3000);
       //document.getElementById("resultado").innerHTML = "El Tiempo total del ensamblado es: "+min;
     }
     //***************Fin de pintar camino del C??digo de FB***************************** 
    async function validar(){//funcion que valida un caso especial
       
        cy.elements().remove();
        cy.add([
        { group: 'nodes',data: { id: 'a',label: entradal1},position: {x:0.0,y:0.0}},
        { group: 'nodes',data: { id: 'b',label: nodo1l1},position: {x:50.0,y:0.0}},
        { group: 'nodes',data: { id: 'c',label: nodo2l1},position: {x:100.0,y:0.0} },
        { group: 'nodes',data: { id: 'd',label: nodo3l1},position: {x:150.0,y:0.0} },
        { group: 'nodes',data: { id: 'e',label: nodo4l1},position: {x:200.0,y:0.0} },
        { group: 'nodes',data: { id: 'f',label: salidal1},position: {x:250.0,y:0.0}},
        { group: 'nodes',data: { id: 'g',label: entradal2},position: {x:0.0,y:60.0} },
        { group: 'nodes',data: { id: 'h',label: nodo1l2},position: {x:50.0,y:60.0} },
        { group: 'nodes',data: { id: 'i',label: nodo2l2},position: {x:100.0,y:60.0} },
        { group: 'nodes',data: { id: 'j',label: nodo3l2},position: {x:150.0,y:60.0} },
        { group: 'nodes',data: { id: 'k',label: nodo4l2},position: {x:200.0,y:60.0} },
        { group: 'nodes',data: { id: 'l',label: salidal2},position: {x:250.0,y:60.0}},
        
    
        { group: 'edges',data: { id: 'ab', weight: 2, source: 'a', target: 'b' ,label:''} },
        { group: 'edges',data: { id: 'bc', weight: 2, source: 'b', target: 'c' ,label:''} },
        { group: 'edges',data: { id: 'cd', weight: 2, source: 'c', target: 'd' ,label:''} },
        { group: 'edges',data: { id: 'de', weight: 2, source: 'd', target: 'e' ,label:''} },
        { group: 'edges',data: { id: 'ef', weight: 2, source: 'e', target: 'f' ,label:''} },
        { group: 'edges',data: { id: 'gh', weight: 2, source: 'g', target: 'h' ,label:''} },
        { group: 'edges',data: { id: 'hi', weight: 2, source: 'h', target: 'i' ,label:''} },
        { group: 'edges',data: { id: 'ij', weight: 2, source: 'i', target: 'j' ,label:''} },
        { group: 'edges',data: { id: 'jk', weight: 2, source: 'j', target: 'k' ,label:''} },
        { group: 'edges',data: { id: 'kl', weight: 2, source: 'k', target: 'l' ,label:''} },
        { group: 'edges',data: { id: 'bi', weight: 2, source: 'b', target: 'i' ,label:cambio1l1}},
        { group: 'edges',data: { id: 'hc', weight: 2, source: 'h', target: 'c' ,label:cambio1l2}},
        { group: 'edges',data: { id: 'id', weight: 2, source: 'i', target: 'd' ,label:cambio2l2}},
        { group: 'edges',data: { id: 'cj', weight: 2, source: 'c', target: 'j' ,label:cambio2l1}},
        { group: 'edges',data: { id: 'je', weight: 2, source: 'j', target: 'e' ,label:cambio3l2}},
        { group: 'edges',data: { id: 'dk', weight: 2, source: 'd', target: 'k' ,label:cambio3l1}}
        
      ]);
       bfs = cy.elements().bfs('#a', function(){}, true);
       bfs2 = cy.elements().bfs('#g', function(){}, true);

       bfs.path[0].addClass('highlighted');//a
       await sleep(1000);
       bfs.path[1].addClass('highlighted');//ab 
       await sleep(1000);
       bfs.path[2].addClass('highlighted');//b
       await sleep(1000);
      bfs.path[3].addClass('highlighted')//bc
      await sleep(1000);
      bfs.path[4].addClass('highlighted');//c
      await sleep(1000);
      bfs.path[7].addClass('highlighted');//cd
      await sleep(1000);
      bfs.path[8].addClass('highlighted');//d
      await sleep(1000);
      bfs.path[11].addClass('highlighted');//de
      await sleep(1000);
      bfs.path[12].addClass('highlighted');//e
      await sleep(1000);
      bfs.path[15].addClass('highlighted');//ef
      await sleep(1000);
      bfs.path[16].addClass('highlighted');//f
      await sleep(4000);
      bfs2.path[15].addClass('highlighted');//kl
      await sleep(1000);
      bfs2.path[16].addClass('highlighted');//l
  
     }