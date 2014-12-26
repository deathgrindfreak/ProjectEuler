;;; Project Euler Problem: 58
;;; Goal: Find the side length for which the ratio of primes to
;;; non-primes lying along the diagonals falls below 10% 
;;; Author: Cooper Bell
;;; Date: 12/11/2014

(use-modules (ProjectEuler projecteuler)
             (ice-9 format)
             (ice-9 pretty-print)
             (srfi srfi-1)
             (srfi srfi-11))


;;; Range of values
(define (range l h)
  (if (>= l h)
      '()
      (cons l (range (+ l 1) h))))


;;; Converts a positive integer to a list of its digits
(define (number->list n)
  (define (rev-to-lst n)
    (if (zero? n)
        '()
        (cons (remainder n 10)
              (rev-to-lst (quotient n 10)))))
  (reverse (rev-to-lst n)))


(define (map-digs lst)
  (map (lambda (x)
         (if (not (= x (car lst)))
             (cons x (cdr lst))
             0))
       (range 0 10)))

(define (replace-digs lst)
  (let ((len (- (length lst) 1)))
    (let loop ((l '()) (i 0))
      (if (< i len)
          (let-values (((head tail) (split-at lst i)))
            (loop (cons (map (lambda (x)
                               (append head x))
                             (map-digs tail))
                        l)
                  (+ i 1)))
          l))))

(pretty-print (replace-digs '(1 2 3 4 5)))
