list = Array.ancestors
p "ancestors: #{list}"

list = Math.constants
p "constants: #{list}"

class Parent
  @@var1 = nil
end

class Child < Parent
  @@var2 = nil
end

list1 = Parent.class_variables
p "class_variables: #{list1}"

list2 = Array.included_modules
p "included_modules: #{list2}"

n1 = Array.instance_methods.size
p "instance_methods: #{n1}"

n2 = Array.public_instance_methods.size
p "public_instance_methods: #{n2}"

n3 = Array.private_instance_methods.size
p "private_instance_methods: #{n3}"

n4 = Array.protected_instance_methods.size
p "protected_instance_methods: #{n4}"

n5 = Array.public_instance_methods(false).size
p "public_instance_methods: #{n5}"
