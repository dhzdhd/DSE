SET SERVEROUTPUT ON

DECLARE
    v_word VARCHAR2(100) := '&v_word';
    v_vowel NUMBER := 0;
    v_consonant NUMBER := 0;
    v_number NUMBER := 0;
    v_special NUMBER := 0;
    v_sub VARCHAR2(1);
BEGIN
    FOR i IN 1..LENGTH(v_word) LOOP
        v_sub := SUBSTR(v_word, i, 1);
        IF REGEXP_LIKE(v_sub, '[aeiouAEIOU]') THEN
            v_vowel := v_vowel + 1;
        ELSIF REGEXP_LIKE(v_sub, '[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]') THEN
            v_consonant := v_consonant + 1;
        ELSIF REGEXP_LIKE(v_sub, '[0-9]') THEN
            v_number := v_number + 1;
        ELSE
            v_special := v_special + 1;
        END IF;
    END LOOP;
    dbms_output.put_line('Vowels ' || v_vowel || ', Consonant ' || v_consonant || ', Number ' || v_number || ', Special ' || v_special);
END;
/
