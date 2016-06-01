class Alpha
  def self.const_missing(name)
    "Alpha has no #{name}"
  end
end

class Beta
  def self.const_missing(name)
    "Beta has no #{name}"
  end
end

class A < Alpha
end

class B < Beta
end

p Alpha::FOO
p Beta::FOO
p A::FOO
p B::FOO
