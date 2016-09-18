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

