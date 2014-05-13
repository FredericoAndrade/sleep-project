$(document).ready(function(){

var data=[0.19, 0.02, 0.51, 0.64, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.57, 0.57, 0.59, 0.54, 0.79, 0.56, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.47, 0.70, 0.51, 0.90, 0.79, 0.41, 0.65, 0.82, 0.54, 0.63, 0.72, 0.65, 0.56, 0.72, 0.56, 0.60, 0.49, 0.49, 0.82, 0.42, 0.54, 0.54, 0.45, 0.54, 0.42, 0.54, 0.44, 0.44, 0.48, 0.39, 0.65, 0.34, 0.68, 0.39, 0.61, 0.65, 0.54, 0.71, 0.45, 0.49, 0.58, 0.47, 0.46, 0.50, 0.46, 0.40, 0.56, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.37, 0.67, 0.57, 0.46, 0.67, 0.46, 0.68, 0.61, 0.70, 0.37, 0.51, 0.37, 0.56, 0.48, 0.59, 0.66, 0.52, 0.67, 0.48, 0.75, 0.99, 0.70, 0.42, 0.53, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.70, 0.80, 0.41, 0.65, 0.47, 0.58, 0.48, 0.54, 0.41, 0.41, 0.56]

var length = $(data).length,
csqsum = 0
for(i=0;i<length;i++){
  var datum = data[i]*12,
  prevDatum = data[i-1]*12,
  datumDeviation = datum-prevDatum,
  a = 1,
  bsq = Math.pow(datumDeviation,2),
  csq = Math.round(Math.sqrt(1+bsq))

  csqsum = csqsum+csq

  console.log("No"+i+", "+datum.toFixed(2)+'"')
  console.log("deviation = "+datumDeviation.toFixed(2))
  console.log("c^2 = "+csq)
  // console.log((i%22))
  console.log("csqint "+csqint)
  console.log("")
}



// [0.19, 0.02, 0.51, 0.64, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.57, 0.57, 0.59, 0.54, 0.79, 0.56, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49]

// [0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.47, 0.70, 0.51, 0.90, 0.79, 0.41, 0.65, 0.82, 0.54, 0.63, 0.72, 0.65, 0.56, 0.72, 0.56, 0.60]

// [0.49, 0.49, 0.82, 0.42, 0.54, 0.54, 0.45, 0.54, 0.42, 0.54, 0.44, 0.44, 0.48, 0.39, 0.65, 0.34, 0.68, 0.39, 0.61, 0.65, 0.54, 0.71]

// [0.45, 0.49, 0.58, 0.47, 0.46, 0.50, 0.46, 0.40, 0.56, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.37, 0.67]

// [0.57, 0.46, 0.67, 0.46, 0.68, 0.61, 0.70, 0.37, 0.51, 0.37, 0.56, 0.48, 0.59, 0.66, 0.52, 0.67, 0.48, 0.75, 0.99, 0.70, 0.42, 0.53]

// [0.57, 0.46, 0.67, 0.46, 0.68, 0.61, 0.70, 0.37, 0.51, 0.37, 0.56, 0.48, 0.59, 0.66, 0.52, 0.67, 0.48, 0.75, 0.99, 0.70, 0.42, 0.53]

})