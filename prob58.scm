#!/usr/bin/guile
!#

;;; Project Euler Problem: 58
;;; Goal: Find the side length for which the ratio of primes to
;;; non-primes lying along the diagonals falls below 10% 
;;; Author: Cooper Bell
;;; Date: 12/11/2014

(use-modules (ProjectEuler projecteuler)
             (ice-9 format) 
             (srfi srfi-1)
             (srfi srfi-11))


;;; Redefine miller-rabin primality test
(define-syntax isprime?
  (syntax-rules ()
    ((isprime? n)
     (miller-rabin n 40))))


;;; Determines the side length that is the goal of the problem
(define (gen-spirals)
  (let ((spirals (lambda (i)
                   (list (+ (* 4 i i) (* -6 i) 3)
                         (+ (* 4 i i) (* -8 i) 5)
                         (+ (* 4 i i) (* -10 i) 7)))))
    (let loop ((i 2) (primes 0))
      (let ((n (- (* 4 i) 3))
            (p (+ primes (fold + 0
                               (map (lambda (x)
                                      (if (isprime? x)
                                          1
                                          0))
                                    (spirals i))))))
        (if (> (/ p n) (/ 1 10))
            (loop (+ i 1) p)
            (- (* 2 i) 1))))))


;;; Generate solution
(format #t "Solution: ~a~%" (gen-spirals))
