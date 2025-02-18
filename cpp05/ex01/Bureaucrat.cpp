#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << "Bureaucrat " << name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name << " destroyed" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return name;
}
int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
    {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
    {
        throw GradeTooLowException();
    }
    grade++;
}

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrate grade " << b.getGrade();
    return out;
}
