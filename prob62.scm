(use-modules (srfi srfi-1)
             (srfi srfi-11))

;;; Need to put most of these functions in my "Standard Module"


(define (range . args)
  "Returns a python style range of numbers"
  (let ((range-fun (lambda (l h step)
                     (let loop ((l l) (lst '()))
                       (if (>= l h)
                           (reverse lst)
                           (loop (+ l step) (cons l lst)))))))
    (case (length args)
      ((1) (range-fun 0 (car args) 1))
      ((2) (range-fun (car args)
                      (cadr args)
                      1))
      ((3) (range-fun (car args)
                      (cadr args)
                      (caddr args)))
      (else (error "Incorrect number of arguments")))))


(define (number->list n)
  "Converts a number to a list"
  (define (lst-help n)
    (if (zero? n)
        '()
        (cons (remainder n 10)
              (lst-help (quotient n 10)))))
  (reverse (lst-help n)))


(define (ispermutation? n m)
  "Determines if a number is a permutation of another number"
  (let ((n-lst (sort-list (number->list n) <))
        (m-lst (sort-list (number->list m) <)))
    (if (equal? n-lst m-lst) #t #f)))


(define (number-of-digits n)
  "Determines the number of digits of a number"
  (if (zero? n)
      0
      (+ 1
         (number-of-digits (quotient n 10)))))


(define (cube-range . args)
  "Returns a range of numbers cubed"
  (let ((cube (lambda (n) (* n n n))))
    (map cube (apply range args))))


(define (number-of-permutations n lst)
  "Returns the number of permutations of a number in a list"
  (fold + 0
        (map (lambda (m)
               (if (ispermutation? n m)
                   1
                   0))
             lst)))


;; (define (iter-perm-check)
;;   "Checks elements against a list to look for cubic permutations"
;;   (let loop (())))
