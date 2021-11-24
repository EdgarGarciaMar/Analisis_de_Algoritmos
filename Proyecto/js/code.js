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