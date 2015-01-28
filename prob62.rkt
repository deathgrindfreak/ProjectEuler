#lang racket

;;;; Project Euler Problem: 62
;;;; Goal: Find the smallest cube that has exactly five permutations
;;;; that are also cubes
;;;; Author: Cooper Bell


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

(define (filter-nums len lst)
  "Filters a sorted list based on len and the number of digits of a number in lst"
  (if (null? lst)
      '()
      (let ((lst-len (number-of-digits (car lst))))
        (cond [(< len lst-len) '()]
              [(> len lst-len) (filter-nums len (cdr lst))]
              [else (cons (car lst)
                          (filter-nums len (cdr lst)))]))))


(define (iter-perm-check num-perms lst)
  "Checks elements against a list to look for cubic permutations"
  (if (null? lst)
      #f
      (let* ((cur (car lst))
             (rest (filter-nums (number-of-digits cur)
                                (cdr lst))))
        (if (>= (number-of-permutations cur rest) num-perms)
            cur
            (iter-perm-check num-perms (cdr lst))))))


(displayln (iter-perm-check (cube-range 9000)))
