# Handling class information
class ClassData

  public

    attr_accessor :name
    attr_accessor :inheritances
    attr_accessor :attributes
    attr_accessor :methods
    attr_accessor :constructors

    def initialize(pName)
      @name = pName
      @inheritances = []
      @attributes = []
      @methods = []
      @constructors = []
      @visibility = "public"
      @comments = ""
    end

# Class
end
