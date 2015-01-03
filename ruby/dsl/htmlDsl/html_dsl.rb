# Attention: This code was extracted from:
# https://codequizzes.wordpress.com/2014/05/07/writing-your-first-ruby-dsl-dsl-to-generate-html/

# =============================================== DSL ========================
class HtmlDsl
  attr_reader :result #It will keep the HTML string.

  def initialize(&block)
    # instance_eval will try to execute the block, however in this case it will 
    # not find any method. Finally method_missing will be called and the block 
    # will be passed to it.
    instance_eval(&block)
  end

  private
  # When ruby try an execute the method, it firstly try to call the method 
  # inside the instance. If it fail, ruby will look in the superclass. Finally
  # if it fail, method_missing will be called. In this example, the "html",
  # "head", "h1", and so forth will be not implement. It means that 
  # method_missing will be called everytime. 
  def method_missing(name, *args, &block)
    tag = name.to_s
    content = args.first
    @result ||= ''
    @result << "<#{tag}>"
    if block_given?
      instance_eval(&block)
    else
      @result << content
    end
    @result << "</#{tag}>"
  end
end

# ============= THIS KIND OF ODE THAT YOU WILL USE!! SIMPLE!!! ===============
html = HtmlDsl.new do
  html do
    head do
      title 'HTML DLS'
    end
    body do
      h1 'H1 TEXT'
      h2 'H2 TEXT'
    end
  end
end

puts html.result
