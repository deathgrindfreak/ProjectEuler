#!/usr/bin/guile
!#

(display %load-path) 
(newline)

(use-modules (ProjectEuler projecteuler)
             (srfi srfi-11)
             (ice-9 pretty-print))

(define int-list (lambda (size)
                   (let lst-loop ((i size) (lst '()))
                     (if (> i 1)
                         (lst-loop (- i 1) (cons i lst))
                         lst))))

(pretty-print
 (map cons (cddr (int-list 1000))
      (map (lambda (x)
             (miller-rabin x 10))
           (cddr (int-list 1000)))))

(miller-rabin 4547337172376300111955330758342147474062293202868155909489 100)
