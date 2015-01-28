;;; Useful algorithms for solving project euler problems

(define-module (ProjectEuler projecteuler)
  #:use-module (srfi srfi-11)
  #:export (miller-rabin
            sieve-of-eratosthenes))

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




;;; Determines if a number is probably prime using the miller-rabin
;;; primality test (returns #t for probably prime, #f for composite
(define (miller-rabin n k)

  ;; Factors n-1 into the form 2^s * d
  (define (factor-n n)
    (let factor-loop ((s 0) (d (- n 1)))
      (if (zero? (modulo d 2))
          (factor-loop (+ s 1) (/ d 2))
          (values s d))))
  
  ;; Test only works for n > 3 
  (if (> n 3)
      (let-values (((s d) (factor-n n)))
        (let witness-loop ((w 0))
          (if (< w k)
              (let* ((a (+ (random (- n 3))
                           2))
                     (x (modulo-expt a d n)))
                (if (or (= x 1)
                        (= x (- n 1)))
                    (witness-loop (+ w 1))
                    (let inner-loop ((ss 0)
                                     (xx (modulo-expt x 2 n)))
                      (if (< ss (- s 1))
                          (cond ((= xx 1) #f)
                                ((= xx (- n 1)) (witness-loop (+ w 1)))
                                (else (inner-loop (+ ss 1)
                                                  (modulo-expt xx 2 n))))
                          #f))))
              #t)))
      (if (= n 2) #t #f)))


;;; Generates a list of primes (the maximum prime being less than or
;;; equal to n) using the sieve of eratosthenes
(define (sieve-of-eratosthenes n)
  (let ((int-list (lambda (size)
                    (let lst-loop ((i (if (odd? size)
                                          size
                                          (- size 1)))
                                   (lst '()))
                      (if (> i 1)
                          (lst-loop (- i 2) (cons i lst))
                          lst)))))
    (let loop ((lst (int-list n)) (result '()))
        (if (null? lst)
            (cons 2 result)
            (let ((fst (car lst)))
              (loop (filter (lambda (x)
                              (not (zero? (modulo x fst))))
                            (cdr lst))
                    (append result (list fst))))))))
