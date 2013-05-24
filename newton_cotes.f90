program newton_cotes
implicit none
real*8 a, b, inte_result
integer :: n =10, if; 
external simpson, f
a = 0.d0; b = 1.d0;
call simpson(f,a,b,n,inte_result,if)
print*, inte_result, if
stop
end program newton_cotes



subroutine simpson(f,a,b,n,integral_result,if)  ! n >10
!***DESCRIPTION
!	in:: f	external function, user defined
!	in:: a	down limit of integrand
!	in:: b	up limit of integrand
!	in:: n	integral zone is divided into n parts, control the ACCURACY
!	out: integral_result   final resualt of the integral.		
real*8 ::  f, x, a, b, ai, bi, d, integral_result,tmp;
integer :: n, i, if
external f
d = (b-a)/n
if = 0; 
integral_result = 0.d0
ai = a; bi = ai +d;  ! first border (ai, bi)
do i =1, n
    tmp = f(ai)+4.d0*f((ai+bi)/2.d0)+f(bi)  ! Simpson's Rule
    tmp = tmp*d/6.d0
    if = if +3 ! times for function is called
    integral_result = integral_result + tmp;
    ai = bi; bi = bi +d;  ! move divided integral region
enddo
return 
end subroutine

real*8 function f(x)
real*8 x
f = exp(-x)*cos(x)
return
end function f

