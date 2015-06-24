(ns prob61)

(def polys '(:triangle :square :pentagonal :hexagonal :heptagonal :octagonal))

(def prangs
  '((fn [] (range 45 141))
    (fn [] (range 32 100))
    (fn [] (range 26 82))
    (fn [] (range 23 71))
    (fn [] (range 21 64))
    (fn [] (range 19 59))))

(def pfuns
  '((fn [n] (/ (* n (inc n)) 2))
    (fn [n] (* n n))
    (fn [n] (/ (* n (- (* 3 n) 1)) 2))
    (fn [n] (* n (- (* 2 n) 1)))
    (fn [n] (/ (* n (- (* 5 n) 3)) 2))
    (fn [n] (* n (- (* 3 n) 2)))))

(def ranges
  (apply hash-map (map polys prangs)))

(def polygonals
  (apply hash-map (map polys pfuns)))

(def poly-vals
  (reduce-kv (fn [m k v]
               (assoc m k (map (k polygonals) (v))))
             {}
             ranges))

(defn cyclical? [n m]
  (= (mod n 100) (quot m 100)))

(defn link-cycs [chains poly]
  (for [c chains
        n poly
        :when (cyclical? (last c) n)]
    (conj c n)))
