#lang racket

;;;; Project Euler Problem: 61
;;;; Goal: Find the sum of the six 4-digit numbers that are either triangular,
;;;; square, pentagonal, hexagonal, heptagonal and octagonal.
;;;; Author: Cooper Bell


;;; generate list of sequential integers in [start, end)
(define (build-lim-list start end)
  (define (build-in lst x end)
    (if (= x end)
      (reverse lst)
      (build-in (cons x lst) (+ x 1) end)))
  (build-in '() start end))
    

;;; generate lists of figurate numbers
(define (triangle start end)
  (map (lambda (n)
         (/ (* n (+ n 1)) 2))
       (build-lim-list start end)))

(define (square start end)
  (map (lambda (n)
         (* n n))
       (build-lim-list start end)))

(define (pentagonal start end)
  (map (lambda (n)
         (/ (* n (- (* 3 n) 1) ) 2))
       (build-lim-list start end)))

(define (hexagonal start end)
  (map (lambda (n)
         (* n (- (* 2 n) 1)))
       (build-lim-list start end)))

(define (heptagonal start end)
  (map (lambda (n)
         (/ (* n (- (* 5 n) 3)) 2))
       (build-lim-list start end)))

(define (octagonal start end)
  (map (lambda (n)
         (* n (- (* 3 n) 2)))
       (build-lim-list start end)))


;;; generate all 4-digit figurative numbers
;;; all "magic numbers" were calculated from the 
;;; formulas for generated the numbers themselves
(define tri (triangle   45 141))
(define squ (square     32 100))
(define pen (pentagonal 26 82))
(define hex (hexagonal  23 71))
(define hep (heptagonal 21 64))
(define oct (octagonal  19 59))


;;; search for cyclical 6-tuple
(define (pair-search)

  ;; figurative number list
  (define figs (list tri squ pen hex hep oct))

  ;; determines if pair of numbers is cyclical (right -> left)
  (define (cyc-pair? a b)
    (if (= (modulo a 100) (quotient b 100))
      #t
      #f))

  ;; find member of figurative numbers (easier to iterate)
  (define (fig-lst i j)
    (list-ref (list-ref figs i) j))

  ;; iterate of lists of figurative numbers to find cyclical 6-tuple
  (define (cyc-test i j k pos-lst)
    (cond
      ;; if length of pos-lst is six, then we have our list
      [(= (length pos-lst) 5) (reverse pos-lst)]
      ;; if a match, shift to next two lists
      [(cyc-pair? (fig-lst i j) (fig-lst (+ i 1) k))
       (cyc-test (+ i 1) k 0 (cons (list j k) pos-lst))]
      ;; if not, and k < length of iter list: goto next element
      [(< k (length (list-ref figs (+ i 1))))
       (cyc-test i j (+ k 1) pos-lst)]
      ;; else, run out of room: iterate j
      [else (if (= i 0)
              (cyc-test 0 (+ j 1) 0 empty)
              (cyc-test 0 (+ (list-ref (list-ref pos-lst 0) 0) 1) 0 empty))]))

  ;; convert list of "coordinates" to actual list
  (define (lst-conv pos-lst)
    (define (lst-conv-in pos-lst actual index)
      (if (= index 6)
        actual
        (lst-conv-in pos-lst 
                     (cons (list-ref figs 
                                     (list-ref (list-ref pos-lst index) 
                                               0)) 
                           actual)
                     (+ index 1))))

    (lst-conv-in  empty 0))

  (lst-conv (cyc-test 0 0 0 empty)))


;;; search!!!
(pair-search)
