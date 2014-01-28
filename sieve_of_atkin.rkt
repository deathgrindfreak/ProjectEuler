#lang racket

;;;; Generates a list of primes using the "Sieve of Atkin."
;;;; More on this algorithm can be found at:
;;;; http://en.wikipedia.org/wiki/Sieve_of_Atkin
;;;; Author: Cooper Bell


;;; sieve the primes
(define (sieve lim)
  (define root (+ (round (sqrt lim)) 1))  ; limit for quadratic values

  ;; quadratic tests for sieve
  (define (quad_one lim l is_prime)
    (if (and (<= l lim) (or (= (modulo l 12) 1) (= (modulo l 12) 5)))
      (begin
        (vector-set! is_prime l (not (vector-ref is_prime l)))
        is_prime)
      is_prime))

  (define (quad_two lim m is_prime)
    (if (and (<= m lim) (= (modulo m 12) 7))
      (begin
        (vector-set! is_prime m (not (vector-ref is_prime m)))
        is_prime)
      is_prime))

  (define (quad_thr lim x y n is_prime)
    (if (and (> x y) (<= n lim) (= (modulo n 12) 11))
      (begin
        (vector-set! is_prime n (not (vector-ref is_prime n)))
        is_prime)
      is_prime))

  (define (quad lim l m n x y is_prime)
    (quad_thr lim x y n (quad_two lim m (quad_one lim l is_prime))))

  (define (sieve-in lim is_prime x y)
    ;; quadratic values for sieving
    (define-values (l m n) (values (+ (* 4 x x) (* y y))
                                   (+ (* 3 x x) (* y y))
                                   (- (* 3 x x) (* y y))))

    ;; sieve
    (if (< x root)
      (if (< y root)
        (sieve-in lim (quad lim l m n x y is_prime) x (+ y 1))
        (sieve-in lim (quad lim l m n x y is_prime) (+ x 1) 0))
      is_prime))  ; return sieved vector

  (sieve-in lim (make-vector lim #f) 0 0))


;;; set the square multiples of primes to false
(define (square-sieve lim is_prime)
  (define root (+ (round (sqrt lim)) 1))

  ;; set squares of n to #f in is_prime
  (define (set-sqrs lim is_prime n k)
    (if (< k lim)
      (begin
        (vector-set! is_prime k #f)
        (set-sqrs lim is_prime n (+ k (* n n))))
      is_prime))

  ;; eliminate squares of primes in is_prime
  (define (ss-in lim is_prime n)
    (if (< n root) 
      (cond
        [(equal? (vector-ref is_prime n) #t)
         (ss-in lim (set-sqrs lim is_prime n (* n n)) (+ n 1))]
        [else (ss-in lim is_prime (+ n 1))])
      is_prime))
  
  (ss-in lim is_prime 5))


;;; set the boolean values in is_prime to actual numbers
(define (btoi is_prime)
 
  ;; loop over all values
  (define (btoi-loop is_prime primes n)
    (if (< n (- (vector-length is_prime) 1))
      (cond
        [(equal? (vector-ref is_prime n) #t)
         (btoi-loop is_prime (cons n primes) (+ n 1))]
        [else (btoi-loop is_prime primes (+ n 1))])
      (cons 2 (cons 3 (cons 5 (reverse primes))))))

  (btoi-loop is_prime empty 7))
      

;;; return list of primes
(define (prime-list n)
  (btoi (square-sieve n (sieve n))))
