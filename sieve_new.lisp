;;;; Generates a list of primes using the "Sieve of Atkin."
;;;; More on this algorithm can be found at:
;;;; http://en.wikipedia.org/wiki/Sieve_of_Atkin
;;;; Author: Cooper Bell

(setf *limit* 50000)    ; limit for maximum prime in list


;;; generate list of "nil" of size lim
(defun nullness (lim)
  (let ((lst '()))
    (do ((x 1 (+ x 1)))
        ((> x lim) lst)
      (setf lst (cons nil lst)))))


;;; sieve the primes
(defun sieve (lim)
  (setf is_prime (nullness lim))
  (do ((x 1 (+ x 1)))
      ((> x (+ (round (sqrt lim)) 1)) is_prime)
    (do ((y 1 (+ y 1)))
        ((> y (+ (round (sqrt lim)) 1)) is_prime)

      (setf n (+ (* 4 x x) (* y y)))
      (if (and (<= n lim) (or (eql (mod n 12) 1) (eql (mod n 12) 5)))
        (setf (nth n is_prime) (not (nth n is_prime))))

      (setf n (+ (* 3 x x) (* y y)))
      (if (and (<= n lim) (eql (mod n 12) 7))
        (setf (nth n is_prime) (not (nth n is_prime))))

      (setf n (- (* 3 x x) (* y y)))
      (if (and (> x y) (<= n lim) (eql (mod n 12) 11))
        (setf (nth n is_prime) (not (nth n is_prime)))))))


;;; set the square multiples of primes to false
(defun square-sieve (lst lim)
  (do ((n 0 (+ n 1)))
      ((> n (+ (round (sqrt lim))) 1) lst)
    (if (eql (nth n lst) 't)
      (do ((k (* n n) (+ k (* n n))))
          ((> k (- lim 1)) lst)
        (setf (nth k lst) nil)))))


;;; print the primes
(defun prime-print (primes)
  (let ((lst '())
        (max-length (list-length primes)))
    (do ((n 1 (+ n 1)))
        ((> n max-length) (cons 2 (cons 3 (reverse lst))))
      (if (eql (nth n primes) 't)
        (setf lst (cons n lst))))))


;;; produce the list of primes (better formatting)
(defun prime-list (lim)
  (prime-print (square-sieve (sieve lim) lim)))


(print (prime-list *limit*))
