today = readline

if today =~ /Saturday|Sunday/
  Object.class_eval { define_method (:activity) {p "playing!"} }
else
  Object.class_eval { define_method (:activity) {p "working!"} }
end
