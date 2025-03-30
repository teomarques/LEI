.data
str: .asciiz "Introduza um número:"

.text
  li  $v0,4
  la  $a0,str
  syscall
  
  li  $v0,5
  syscall  # $v0 - resultado
  
  move $a0,$v0
  li  $v0, 1
  syscall
  
  li  $v0,10