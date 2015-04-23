(ns prob81.core
  (:require [clojure.string :as str]))

(defn readMatrix [dir]
  (with-open [rdr (reader "./p081_matrix.txt")]
    (let [matrix []]
      (doseq [line (line-seq rdr)]
        (conj matrix (map #(parse-int %)
                          (str/split line #",")))))))

(defn parse-int [s]
  (Integer. (re-find #"\d+" s)))
