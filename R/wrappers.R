# Wrapper function to invoke "helloA" at the shell.
helloA <- function() {
  system(paste(getwd(),"helloA",sep="/"))
}

# Wrapper function to invoke helloB with a named argument
dyn.load("helloB.so")
helloB <- function() {
  result <- .C("helloB",
               greeting="")
  return(result$greeting)
}


#Wrapper function to invoke helloC with two arguments
dyn.load("helloC.so")
helloC <- function(greeting) {
  if (!is.character(greeting)) {
    stop("Argument 'greeting' must be of type 'character'.")
  }
  result <- .C("helloC",
               greeting=greeting,
               count=as.integer(1))
  return(result$count)
}

# wrapper function to invoke cconv 
dyn.load("cconv.so")
rconv <- function(lag,x) {
 .C("cconv",
  as.integer(lag),
  as.double(x),
  as.integer(length(x)),
  as.double(0.0))[[4]]
}

# wrapper function for cconv2
dyn.load("cconv2.so")
rconv2 <- function(lag,x) {
  .C("cconv2",
  as.integer(lag),
  as.integer(length(lag)),
  as.double(x),
  as.integer(length(x)),
  as.double(vector("double",length(lag))))[[5]]
}
