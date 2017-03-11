(def shift? >)

(defn count-shifts [container current-node-value index-to-check & {:keys [num-shifts]
                                                                   :or   {num-shifts 0}
                                                                  }
                   ]
  (let [check-value (nth container index-to-check nil)]
    (if (nil? check-value)
      num-shifts
      (if (shift? current-node-value check-value)
        (count-shifts container current-node-value (+ index-to-check 1) :num-shifts (+ num-shifts 1))
        (count-shifts container current-node-value (+ index-to-check 1) :num-shifts num-shifts)
      )
    )
  )
)

(defn perform-single-test [container & {:keys [current-node num-shifts]
                                        :or   {current-node 0
                                               num-shifts   0
                                              }
                                       }
                          ]
  (let [current-node-val (nth container current-node nil)]
    (if (nil? current-node-val)
      num-shifts
      (let [next-node (+ 1 current-node)]
        (perform-single-test container
                             :current-node next-node
                             :num-shifts   (+ num-shifts
                                              (count-shifts container
                                                            current-node-val
                                                            next-node
                                              )
                                           )
        )
      )
    )
  )
)

(defn perform-all-tests []
  ; our "base case" is when there is no lines remaining in the
  ; document; if there is a line the content indicates how many
  ; elements are in the array, which is irrelevant to this algorithm
  (when (not (nil? (read-line)))
    (println (perform-single-test (map read-string (.split (read-line) " "))))
    (perform-all-tests)
  )
)

(defn main []
  ; read (and ignore) the line indicating the number of tests
  (read-line)
  (perform-all-tests)
)

(main)

