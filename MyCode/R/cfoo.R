cfoo=function(a,b) {
   .C('cfoo',
      as.double(a),
      as.double(b),
      c=as.double(0))$c
}
