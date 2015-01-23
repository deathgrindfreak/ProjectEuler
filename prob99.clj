(ns prob99.core
  (:gen-class))

(defn pow_test
  "Takes in two exponential expressions (base power base power)
and produces the base of the larger number"
  [a b c d]
  (let [left (float (/ b d))
        right (float (/ (Math/log c) (Math/log a)))]
    (if (> left right)
      a
      c)))
