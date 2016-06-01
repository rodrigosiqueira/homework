ObjectSpace.each_object do |obj|
  printf "%20s: %s\n", obj.class, obj.inspect
end
