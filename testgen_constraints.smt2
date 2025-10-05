(set-logic ALL)
(set-option :produce-models true)

(declare-fun v1 () String)
(declare-fun v2 () String)
(declare-fun v3 () String)
(declare-fun v4 () String)

; Map: S
(declare-const Dom_S (Array String Bool))
(declare-const Val_S (Array String String))

; Map: S_old
(declare-const Dom_S_old (Array String Bool))
(declare-const Val_S_old (Array String String))

; Map: T
(declare-const Dom_T (Array String Bool))
(declare-const Val_T (Array String String))

; Map: U
(declare-const Dom_U (Array String Bool))
(declare-const Val_U (Array String String))

(assert (> (str.len v2) 0))
(assert (> (str.len v1) 0))

(assert (! (and (select Dom_T v1) (select Dom_U (select Val_T v1))) :named c1))
(assert (! (and (= Dom_S_old Dom_S) (= Val_S_old Val_S)) :named c2))
(assert (! (and (= Dom_S (store Dom_S_old v4 true)) (= Val_S Val_S_old)) :named c3))

(check-sat)
(get-model)
