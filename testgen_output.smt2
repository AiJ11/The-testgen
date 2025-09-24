(set-logic ALL)
(set-option :produce-models true)

(declare-fun v1 () String)
(declare-fun v2 () String)
(declare-fun v3 () String)
(declare-fun v4 () String)
(declare-fun v5 () String)
(declare-fun v6 () String)
(declare-fun v7 () String)

; Map: S
(declare-const Dom_S (Array String Bool))
(declare-const Val_S (Array String String))

; Map: T
(declare-const Dom_T (Array String Bool))
(declare-const Val_T (Array String String))

; Map: U
(declare-const Dom_U (Array String Bool))
(declare-const Val_U (Array String String))

(assert (> (str.len v2) 0))
(assert (> (str.len v1) 0))

(assert (! (and (select Dom_T v1) (select (mapAcess v3 v1)_domain v4)) :named c1))
(assert (! (= v5 (set_union v6 v7)) :named c2))

(check-sat)
(get-model)
