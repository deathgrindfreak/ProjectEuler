(use-modules (srfi srfi-1)
             (srfi srfi-11))

;;; Need to put most of these functions in my "Standard Module"


;;; Returns a python style range of numbers
(define (range . args)
  (letrec ((range-fun (lambda (l h step)
                        (if (>= l h)
                            '()
                            (cons l
                                  (range-fun (+ l step)
                                             h
                                             step))))))
    (case (length args)
      ((1) (range-fun 0 (car args) 1))
      ((2) (range-fun (car args)
                      (cadr args)
                      1))
      ((3) (range-fun (car args)
                      (cadr args)
                      (caddr args)))
      (else (scm-error 'range "Incorrect number of arguments")))))


;;; Converts a number to a list
(define (number->list n)
  (define (lst-help n)
    (if (zero? n)
        '()
        (cons (remainder n 10)
              (lst-help (quotient n 10)))))
  (reverse (lst-help n)))


;;; Determines if a number is a permutation of another number
(define (ispermutation? n m)
  (let ((n-lst (sort-list (number->list n) <))
        (m-lst (sort-list (number->list m) <)))
    (if (equal? n-lst m-lst) #t #f)))


;;; Returns a range of numbers cubed
(define (cube-range . args)
  (let ((cube (lambda (n) (* n n n))))
    (map cube (apply range args))))
