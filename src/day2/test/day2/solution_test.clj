(ns day2.solution-test
  (:require [clojure.test :refer [deftest, testing, is]]
            [day2.solution :as solution]))

(deftest get-score-part-two-test 
  (testing "Fail: get-score-part-two, unexpected score"
    (is (= 3 (solution/get-score-part-two "A" "X")))
    (is (= 4 (solution/get-score-part-two "A" "Y")))
    (is (= 8 (solution/get-score-part-two "A" "Z")))
    (is (= 1 (solution/get-score-part-two "B" "X")))
    (is (= 5 (solution/get-score-part-two "B" "Y")))
    (is (= 9 (solution/get-score-part-two "B" "Z")))
    (is (= 2 (solution/get-score-part-two "C" "X")))
    (is (= 6 (solution/get-score-part-two "C" "Y")))
    (is (= 7 (solution/get-score-part-two "C" "Z")))))