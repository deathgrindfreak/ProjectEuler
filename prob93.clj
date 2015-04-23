(ns prob93
  (:gen-class))

(defn distinct-digs []
  (for [a (range 10) b (range 10) c (range 10) d (range 10)
        :when (< a b c d)]
    [a b c d]))

(defn permutate-operations [num]
  (let [[a b c d] num
        ops [+ - * /]]
    ))

(defn -main [& args]
  (println (distinct-digs)))
