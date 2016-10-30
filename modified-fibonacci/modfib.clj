(defn square [n] (* n n))

(defn modfib-aux [n-2 n-1 n]
  "Implements the modified fibonacci algorithm. Does not validate inputs"
  (if (= n 0)
    n-1
    (recur n-1 (+ n-2 (square n-1)) (- n 1))
  )
)

(defn modfib [first-term second-term n]
  "Validates inputs and does pre-processing of \"n\""
  (cond
    (< n 1) (throw "Cannot accept an \"n\" of less than 1!")
    (= n 1) first-term
    (= n 2) second-term
    true (modfib-aux first-term second-term (- n 2))
  )
)

; reads in the 3 arguments from stdin and performs the algorithm
(defn main []
  "Reads in the 3 arguments to the modified fibonacci algorithm from standard input and prints the result to standard output"
  (def args (map bigint (map read-string (.split (read-line) " "))))
  (println (.toString (modfib (first args) (second args) (nth args 2))))
)

(main)

