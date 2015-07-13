(ns prob64)


(defn partial-fracs [n]
  (let [c0 (int (Math/floor (Math/sqrt n)))]

    (defn periodic? [c]
      (if (or (empty? c)
              (odd? (count c))) 
        false
        (let [cnt (/ (count c) 2)
              [h t] (split-at cnt c)]
          (= h t))))

    (defn p-fracs [c d r]
      (if (not (periodic? c))
        (let [dp (int (/ (- n (* r r)) d))
              cp (int (dec (Math/ceil (/ (+ (Math/sqrt n) 
                                            r) 
                                         dp))))
              rp (int (Math/abs (- r (* cp dp))))]
          (recur (conj c cp) dp rp))
        (list (/ (count c) 2) c)))

    (p-fracs [] 1 c0)))
