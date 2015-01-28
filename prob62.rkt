#lang racket


(define (cube-range n)
  (build-list n (lambda (x) (* x x x))))


(define (number->list n)
  "Converts a number to a list"
  (define (lst-help n)
    (if (zero? n)
        '()
        (cons (remainder n 10)
              (lst-help (quotient n 10)))))
  (reverse (lst-help n)))


(define (number-of-digits n)
  "Determines the number of digits of a number"
  (if (zero? n)
      0
      (+ 1
         (number-of-digits (quotient n 10)))))


(define (ispermutation? n m)
  "Determines if a number is a permutation of another number"
  (let ((n-lst (sort (number->list n) <))
        (m-lst (sort (number->list m) <)))
    (if (equal? n-lst m-lst) #t #f)))


(define (number-of-permutations n lst)
  "Returns the number of permutations of a number in a list"
  (foldr (lambda (m l)
           (if (ispermutation? n m)
               (+ 1 l)
               l))
         0
         lst))


(define (iter-perm-check lst)
  "Checks elements against a list to look for cubic permutations"
  (let loop ((i (car lst)) (lst (cdr lst)))
    (if (null? lst)
        #f
        (if (= (number-of-permutations i lst) 3)
            i
            (loop (car lst) (cdr lst))))))


(iter-perm-check (cube-range 1 1000))
